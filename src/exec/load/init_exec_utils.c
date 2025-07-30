/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:03:54 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/29 20:12:56 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_north_values(t_map *map)
{
	if (map->letter == 'N')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = -1.0;
		map->player->plane_x = 0.66;
		map->player->plane_y = 0.0;
	}
}

void	set_south_values(t_map *map)
{
	if (map->letter == 'S')
	{
		map->player->dir_x = 0.0;
		map->player->dir_y = 1.0;
		map->player->plane_x = -0.66;
		map->player->plane_y = 0.0;
	}
}

void	set_east_values(t_map *map)
{
	if (map->letter == 'E')
	{
		map->player->dir_x = 1.0;
		map->player->dir_y = 0.0;
		map->player->plane_x = 0.0;
		map->player->plane_y = 0.66;
	}
}

void	set_west_values(t_map *map)
{
	if (map->letter == 'W')
	{
		map->player->dir_x = -1.0;
		map->player->dir_y = 0.0;
		map->player->plane_x = 0.0;
		map->player->plane_y = -0.66;
	}
}
