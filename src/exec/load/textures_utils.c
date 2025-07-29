/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:34:42 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/28 18:40:20 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	load_north_texture(t_map *map)
{
	printf("DEBUG: entering load_north_texture\n");
	map->text->north = (t_data_img *)malloc(sizeof(t_data_img));
	if (!map->text->north)
		exit_error("Error allocating memory for North texture\n", map);
	map->text->north->img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->info->north_path, &map->text->north->width,
			&map->text->north->height);
	if (!map->text->north->img_ptr)
		exit_error("Error loading texture NO\n", map);
	map->text->north->addr = mlx_get_data_addr(map->text->north->img_ptr,
			&map->text->north->bits_per_pixel,
			&map->text->north->line_length, &map->text->north->endian);
	printf("DEBUG: img_ptr: %p\n", map->text->north->img_ptr);
	printf("DEBUG: BPP:  %d\n", map->text->north->bits_per_pixel);
	printf("DEBUG: line_length: %d\n", map->text->north->line_length);
	printf("DEBUG: endian: %d\n", map->text->north->endian);
}

void	load_south_texture(t_map *map)
{
	map->text->south = (t_data_img *)malloc(sizeof(t_data_img));
	if (!map->text->south)
		exit_error("Error allocating memory for South texture\n", map);
	map->text->south->img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->info->south_path, &map->text->south->width,
			&map->text->south->height);
	if (!map->text->south->img_ptr)
		exit_error("Error loading texture SO\n", map);
	map->text->south->addr = mlx_get_data_addr(map->text->south->img_ptr,
			&map->text->south->bits_per_pixel,
			&map->text->south->line_length, &map->text->south->endian);
}

void	load_east_texture(t_map *map)
{
	map->text->east = (t_data_img *)malloc(sizeof(t_data_img));
	if (!map->text->east)
		exit_error("Error allocating memory for East texture\n", map);
	map->text->east->img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->info->east_path, &map->text->east->width,
			&map->text->east->height);
	if (!map->text->east->img_ptr)
		exit_error("Error loading texture EA\n", map);
	map->text->east->addr = mlx_get_data_addr(map->text->east->img_ptr,
			&map->text->east->bits_per_pixel,
			&map->text->east->line_length, &map->text->east->endian);
}

void	load_west_texture(t_map *map)
{
	map->text->west = (t_data_img *)malloc(sizeof(t_data_img));
	if (!map->text->west)
		exit_error("Error allocating memory for West texture\n", map);
	map->text->west->img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
			map->info->west_path, &map->text->west->width,
			&map->text->west->height);
	if (!map->text->west->img_ptr)
		exit_error("Error loading texture WE\n", map);
	map->text->west->addr = mlx_get_data_addr(map->text->west->img_ptr,
			&map->text->west->bits_per_pixel,
			&map->text->west->line_length, &map->text->west->endian);
}
