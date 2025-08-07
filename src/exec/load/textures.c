/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:48:14 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/07 17:46:32 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_textures(t_map *map)
{
	if (!map || !map->text || !map->info)
	{
		printf("NULL pointer vishhh\n");
		exit(1);
	}
	load_north_texture(map);
	load_south_texture(map);
	load_east_texture(map);
	load_west_texture(map);
}
