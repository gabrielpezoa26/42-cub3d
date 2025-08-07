/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:41:15 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/07 13:04:17 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	convert_rgb_colors(t_map *map)
{
	rgb_to_int(map->info->floor_color[0],
		map->info->floor_color[1], map->info->floor_color[2]);
	rgb_to_int(map->info->ceiling_color[0],
		map->info->ceiling_color[1], map->info->ceiling_color[2]);
}

void	init_texture_struct(t_map *map)
{
	map->text = ft_calloc(1, sizeof(t_texture));
	if (!map->text)
		exit_error("Error allocating memory for textures struct", map);
}

void	init_data_img(t_map *map)
{
	map->img = ft_calloc(1, sizeof(t_data_img));
	if (!map->img)
		exit_error("Error allocating memory for main image struct", map);
}

void	my_mlx_pixel_put(t_data_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
