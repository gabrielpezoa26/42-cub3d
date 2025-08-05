/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/05 09:10:44 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player->position_x + map->player->dir_x * MOVE_SPEED;
	new_y = map->player->position_y + map->player->dir_y * MOVE_SPEED;
	if (map->matrix[(int)new_y][(int)new_x] != WALL_VALUE)
	{
		map->player->position_x = new_x;
		map->player->position_y = new_y;
	}
}

void	move_backward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player->position_x - map->player->dir_x * MOVE_SPEED;
	new_y = map->player->position_y - map->player->dir_y * MOVE_SPEED;
	if (map->matrix[(int)new_y][(int)new_x] != WALL_VALUE)
	{
		map->player->position_x = new_x;
		map->player->position_y = new_y;
	}
}

void	move_left(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player->position_x - map->player->plane_x * MOVE_SPEED;
	new_y = map->player->position_y - map->player->plane_y * MOVE_SPEED;
	if (map->matrix[(int)new_y][(int)new_x] != WALL_VALUE)
	{
		map->player->position_x = new_x;
		map->player->position_y = new_y;
	}
}

void	move_right(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player->position_x + map->player->plane_x * MOVE_SPEED;
	new_y = map->player->position_y + map->player->plane_y * MOVE_SPEED;
	if (map->matrix[(int)new_y][(int)new_x] != WALL_VALUE)
	{
		map->player->position_x = new_x;
		map->player->position_y = new_y;
	}
}

void	rotate_left(t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	old_dir_x = map->player->dir_x;
	old_plane_x = map->player->plane_x;
	rot_speed = -0.05;
	map->player->dir_x = map->player->dir_x * cos(rot_speed) - map->player->dir_y * sin(rot_speed);
	map->player->dir_y = old_dir_x * sin(rot_speed) + map->player->dir_y * cos(rot_speed);
	map->player->plane_x = map->player->plane_x * cos(rot_speed) - map->player->plane_y * sin(rot_speed);
	map->player->plane_y = old_plane_x * sin(rot_speed) + map->player->plane_y * cos(rot_speed);
}

void	rotate_right(t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	old_dir_x = map->player->dir_x;
	old_plane_x = map->player->plane_x;
	rot_speed = 0.05;
	map->player->dir_x = map->player->dir_x * cos(rot_speed) - map->player->dir_y * sin(rot_speed);
	map->player->dir_y = old_dir_x * sin(rot_speed) + map->player->dir_y * cos(rot_speed);
	map->player->plane_x = map->player->plane_x * cos(rot_speed) - map->player->plane_y * sin(rot_speed);
	map->player->plane_y = old_plane_x * sin(rot_speed) + map->player->plane_y * cos(rot_speed);
}
