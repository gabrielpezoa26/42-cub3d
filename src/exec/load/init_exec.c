/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:36:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/29 20:12:39 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_direction_values(t_map *map)
{
	set_north_values(map);
	set_south_values(map);
	set_east_values(map);
	set_west_values(map);
	printf("DEBUG: set_direction_values() finished\n");
}

void	init_player(t_map *map)
{
	map->player = ft_calloc(1, sizeof(t_player));
	if (!map->player)
		exit_error("Error allocating memory for player struct", map);
	map->player->position_x = map->pov->x + 0.5;
	map->player->position_y = map->pov->y + 0.5;
	set_direction_values(map);
}
