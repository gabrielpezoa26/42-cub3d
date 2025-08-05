/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:49:32 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/05 09:06:11 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	execution(t_map *map)
{
	init_graphics(map);
	init_textures(map);
	init_player(map);
	mlx_hook(map->window_ptr, 2, 1L<<0, key_press_hook, map); // KeyPress
	mlx_hook(map->window_ptr, 3, 1L<<1, key_release_hook, map); // KeyRelease
	mlx_hook(map->window_ptr, 17, 0, close_game, map);
	mlx_loop_hook(map->mlx_ptr, render, map);
	mlx_loop(map->mlx_ptr);
	printf("DEBUG: execution() -> finished\n");
}