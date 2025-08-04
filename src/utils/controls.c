/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:15:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/04 18:35:24 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 65307)
		close_game(map);
	if (keycode == 'w')
		move_forward(map);
	if (keycode == 's')
		move_backward(map);
	if (keycode == 'a')
		move_left(map);
	if (keycode == 'd')
		move_right(map);
	if (keycode == 65361) // Seta para a esquerda
		rotate_left(map);
	if (keycode == 65363) // Seta para a direita
		rotate_right(map);
	return (0);
}
