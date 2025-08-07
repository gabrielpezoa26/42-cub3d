/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:46:26 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/07 12:25:38 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_graphics(t_map *map)
{
	init_texture_struct(map);
	init_data_img(map);
	map->mlx_ptr = mlx_init();
	map->window_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, TITLE);
	map->img->img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->img->addr = mlx_get_data_addr(map->img->img_ptr,
			&map->img->bits_per_pixel,
			&map->img->line_length, &map->img->endian);
}
