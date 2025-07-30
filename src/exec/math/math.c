/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:36:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/29 16:24:54 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void identify_direction(t_map *map)
{
	if (map->letter == 'N')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = -1.0;
		map->player->plane_x = 0.66;
		map->player->plane_y = 0.0;
	}
	if (map->letter == 'S')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = 1.0;
		map->player->plane_x = -0.66;
		map->player->plane_y = 0.0;
	}
	if (map->letter == 'E')
	{
		map->player->dir_x = 1.0;
		map->player->dir_y = 0.0;
		map->player->plane_x = 0.0;
		map->player->plane_y = 0.66;
	}
	if (map->letter == 'W')
	{
		map->player->dir_x = -1.0;
		map->player->dir_y = 0.0;
		map->player->plane_x = 0.0;
		map->player->plane_y = -0.66;
	}
	printf("DEBUG: identify_direction() finished\n");
}

void	init_player(t_map *map)
{
	map->player = ft_calloc(1, sizeof(t_player));
	if (!map->player)
		exit_error("Error allocating memory for player struct", map);
	map->player->position_x = map->pov->x + 0.5;
	map->player->position_y = map->pov->y + 0.5;
	identify_direction(map);
}
