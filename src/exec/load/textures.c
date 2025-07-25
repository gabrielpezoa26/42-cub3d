/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:48:14 by diego             #+#    #+#             */
/*   Updated: 2025/07/24 21:11:05 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	init_textures(t_texture *text)
{
	text->north = NULL;
	text->south = NULL;
	text->east = NULL;
	text->west = NULL;
}

void	load_textures(t_map *map)
{
	map->text = (t_texture *)malloc(sizeof(t_texture));
	if (!map->text)
		exit_error("Error trying to malloc text\n", map);
	init_textures(map->text);
	map->text->north = mlx_load_xpm42(map->info->north_path);
	if (!map->text->north)
		exit_error("Error loading texture NO\n", map);
	map->text->south = mlx_load_xpm42(map->info->south_path);
	if (!map->text->south)
		exit_error("Error loading texture SO\n", map);
	map->text->east = mlx_load_xpm42(map->info->east_path);
	if (!map->text->east)
		exit_error("Error loading texture EA\n", map);
	map->text->west = mlx_load_xpm42(map->info->west_path);
	if (!map->text->west)
		exit_error("Error loading texture WE\n", map);
}
