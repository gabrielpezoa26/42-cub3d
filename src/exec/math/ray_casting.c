/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:13:53 by diego             #+#    #+#             */
/*   Updated: 2025/08/05 15:37:44 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	direction(t_player *player, t_ray *ray, int index)
{
	ray->cam_x = 2 * index / (double)WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->cam_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->cam_x;
}

static void	calculate_distance(t_ray *ray, t_player *player)
{
	(void)player;
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist_x - ray->delta_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_y);
}

static void	calculate_wall(t_ray *ray)
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

static void	draw_column(t_map *map, int x)
{
	draw_ceiling_and_floor(map, x);
	draw_textured_wall(map, x);
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
