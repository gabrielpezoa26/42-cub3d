
#include "../../includes/cub3d.h"

void my_mlx_pixel_put(t_data_img *img, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static t_data_img	*get_texture(t_map *map)
{
	if (map->ray.side == 0)
	{
		if (map->ray.ray_dir_x > 0)
			return (map->text->east);
		else
			return (map->text->west);
	}
	else
	{
		if (map->ray.ray_dir_y > 0)
			return (map->text->south);
		else
			return (map->text->north);
	}
}

static void direction(t_player *player, t_ray *ray, int index)
{
	ray->cam_x = 2 * index / (double)WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->cam_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->cam_x;
}

static void	set_dda_step(t_player *player, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->position_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->position_x) \
			* ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->position_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->position_y) \
			* ray->delta_y;
	}
}

static void	dda(t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->position_x;
	ray->map_y = (int)player->position_y;
	if (ray->ray_dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->ray_dir_y);
	set_dda_step(player, ray);
}

void	loop_dda(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->matrix[ray->map_y][ray->map_x] == WALL_VALUE)
			ray->hit = 1;
	}
}

void	calculate_distance(t_ray *ray, t_player *player)
{
	(void)player;
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist_x - ray->delta_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_y);
}

void	calculate_wall(t_ray *ray)
{
	if (ray->wall_dist < 0.0001)
		ray->wall_dist = 0.0001;
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
}

static void	draw_ceiling_and_floor(t_map *map, int x)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_int(map->info->ceiling_color[0], \
		map->info->ceiling_color[1], map->info->ceiling_color[2]);
	floor_color = rgb_to_int(map->info->floor_color[0], \
		map->info->floor_color[1], map->info->floor_color[2]);
	y = 0;
	while (y < map->ray.start)
	{
		my_mlx_pixel_put(map->img, x, y, ceiling_color);
		y++;
	}
	y = map->ray.end;
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(map->img, x, y, floor_color);
		y++;
	}
}

static int	calculate_texture_x(t_map *map, t_data_img *texture, \
	double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)texture->width);
	if ((map->ray.side == 0 && map->ray.ray_dir_x < 0) || \
		(map->ray.side == 1 && map->ray.ray_dir_y > 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static double	get_wall_hit_coordinate(t_map *map)
{
	double	wall_x;

	if (map->ray.side == 0)
		wall_x = map->player->position_y + map->ray.wall_dist * \
			map->ray.ray_dir_y;
	else
		wall_x = map->player->position_x + map->ray.wall_dist * \
			map->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

static void	draw_textured_wall(t_map *map, int x)
{
	t_data_img	*texture;
	int			tex_x;
	int			tex_y;
	int			y;
	int			color;

	texture = get_texture(map);
	tex_x = calculate_texture_x(map, texture, get_wall_hit_coordinate(map));
	y = map->ray.start;
	while (y < map->ray.end)
	{
		tex_y = (int)(((y - (double)HEIGHT / 2 + \
			(double)map->ray.line_height / 2) * texture->height) / \
			(double)map->ray.line_height);
		color = get_texture_color(texture, tex_x, tex_y);
		my_mlx_pixel_put(map->img, x, y, color);
		y++;
	}
}

void	draw_column(t_map *map, int x)
{
	draw_ceiling_and_floor(map, x);
	draw_textured_wall(map, x);
}

void	update_player_position(t_map *map)
{
	if (map->player->is_moving_forward)
		move_forward(map);
	if (map->player->is_moving_backward)
		move_backward(map);
	if (map->player->is_moving_left)
		move_left(map);
	if (map->player->is_moving_right)
		move_right(map);
	if (map->player->is_rotating_left)
		rotate_left(map);
	if (map->player->is_rotating_right)
		rotate_right(map);
}

int	render(void *param)
{
	t_map	*map;
	int		x;

	map = (t_map *)param;
	update_player_position(map);
	x = 0;
	while (x < WIDTH)
	{
		direction(map->player, &map->ray, x);
		dda(&map->ray, map->player);
		loop_dda(&map->ray, map);
		calculate_distance(&map->ray, map->player);
		calculate_wall(&map->ray);
		draw_column(map, x);
		x++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, \
		map->img->img_ptr, 0, 0);
	return (0);
}
