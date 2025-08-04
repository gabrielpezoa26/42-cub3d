/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:15:57 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/04 16:37:02 by gcesar-n         ###   ########.fr       */
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
	return (0);
}
