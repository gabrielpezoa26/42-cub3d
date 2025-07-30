/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:41:15 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/30 14:45:35 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	convert_rgb_colors(t_map *map)
{
	int	floor_color;
	int	ceiling_color;

	floor_color = rgb_to_int(map->info->floor_color[0],
			map->info->floor_color[1], map->info->floor_color[2]);
	ceiling_color = rgb_to_int(map->info->ceiling_color[0],
			map->info->ceiling_color[1], map->info->ceiling_color[2]);
	printf("DEBUG: Cor do chão convertida: %d\n", floor_color);
	printf("DEBUG: Cor do teto convertida: %d\n", ceiling_color);
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
