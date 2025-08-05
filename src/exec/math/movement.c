/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/05 15:32:24 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_forward(t_map *map)
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

static void	move_backward(t_map *map)
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

static void	move_left(t_map *map)
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

static void	move_right(t_map *map)
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
		rotate_left(map->player);
	if (map->player->is_rotating_right)
		rotate_right(map->player);
}
