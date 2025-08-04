/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/04 16:55:27 by gcesar-n         ###   ########.fr       */
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
