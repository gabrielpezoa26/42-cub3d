/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/04 18:38:26 by diego            ###   ########.fr       */
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

void	move_right(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player->position_x - map->player->dir_y * MOVE_SPEED;
	new_y = map->player->position_y + map->player->dir_x * MOVE_SPEED;
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

	new_x = map->player->position_x + map->player->dir_y * MOVE_SPEED;
	new_y = map->player->position_y - map->player->dir_x * MOVE_SPEED;
	if (map->matrix[(int)new_y][(int)new_x] != WALL_VALUE)
	{
		map->player->position_x = new_x;
		map->player->position_y = new_y;
	}
}

// Em src/exec/math/movement.c
void rotate_left(t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;
	
	old_dir_x = map->player->dir_x;
	old_plane_x = map->player->plane_x;
	map->player->dir_x = old_dir_x * cos(-ROT_SPEED) - map->player->dir_y * sin(-ROT_SPEED);
	map->player->dir_y = old_dir_x * sin(-ROT_SPEED) + map->player->dir_y * cos(-ROT_SPEED);
	map->player->plane_x = old_plane_x * cos(-ROT_SPEED) - map->player->plane_y * sin(-ROT_SPEED);
	map->player->plane_y = old_plane_x * sin(-ROT_SPEED) + map->player->plane_y * cos(-ROT_SPEED);
}

void rotate_right(t_map *map)
{
	double	old_dir_x;
	double	old_plane_x;
	
	old_dir_x = map->player->dir_x;
	old_plane_x = map->player->plane_x;
	map->player->dir_x = old_dir_x * cos(ROT_SPEED) - map->player->dir_y * sin(ROT_SPEED);
	map->player->dir_y = old_dir_x * sin(ROT_SPEED) + map->player->dir_y * cos(ROT_SPEED);
	map->player->plane_x = old_plane_x * cos(ROT_SPEED) - map->player->plane_y * sin(ROT_SPEED);
	map->player->plane_y = old_plane_x * sin(ROT_SPEED) + map->player->plane_y * cos(ROT_SPEED);
}
