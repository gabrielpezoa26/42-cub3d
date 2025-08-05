/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:17:19 by dteruya           #+#    #+#             */
/*   Updated: 2025/08/05 15:32:34 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	draw_textured_wall(t_map *map, int x)
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

void	draw_ceiling_and_floor(t_map *map, int x)
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
