/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:15:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/05 09:05:03 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press_hook(int keycode, t_map *map)
{
	if (keycode == 65307) // ESC
		close_game(map);
	if (keycode == 'w')
		map->player->is_moving_forward = true;
	if (keycode == 's')
		map->player->is_moving_backward = true;
	if (keycode == 'a')
		map->player->is_moving_left = true;
	if (keycode == 'd')
		map->player->is_moving_right = true;
	if (keycode == 65361)
		map->player->is_rotating_left = true;
	if (keycode == 65363)
		map->player->is_rotating_right = true;
	return (0);
}

int	key_release_hook(int keycode, t_map *map)
{
	if (keycode == 'w')
		map->player->is_moving_forward = false;
	if (keycode == 's')
		map->player->is_moving_backward = false;
	if (keycode == 'a')
		map->player->is_moving_left = false;
	if (keycode == 'd')
		map->player->is_moving_right = false;
	if (keycode == 65361)
		map->player->is_rotating_left = false;
	if (keycode == 65363)
		map->player->is_rotating_right = false;
	return (0);
}
