/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:10:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/29 18:22:03 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_info(t_info *info)
{
	if (!info)
		return ;
	if (info->north_path)
		free(info->north_path);
	if (info->south_path)
		free(info->south_path);
	if (info->west_path)
		free(info->west_path);
	if (info->east_path)
		free(info->east_path);
	free(info);
}

void	free_matrix(int **matrix, int height)
{
	int	i;

	if (matrix == NULL)
		return ;
	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	free_textures(void *mlx_ptr, t_texture *textures)
{
	if (!textures)
		return ;
	free_single_texture(mlx_ptr, textures->north);
	free_single_texture(mlx_ptr, textures->south);
	free_single_texture(mlx_ptr, textures->east);
	free_single_texture(mlx_ptr, textures->west);
	free(textures);
}

void	free_map(t_map **map)
{
	if (!(*map))
		return ;
	if ((*map)->matrix)
		free_matrix((*map)->matrix, (*map)->rows_amount);
	if ((*map)->pov)
		free((*map)->pov);
	if ((*map)->player)
		free((*map)->player);
	if ((*map)->info)
		free_info((*map)->info);
	if ((*map)->text)
		free_textures((*map)->mlx_ptr, (*map)->text);
	if ((*map)->img)
		free_single_texture((*map)->mlx_ptr, (*map)->img);
	if ((*map)->window_ptr)
		mlx_destroy_window((*map)->mlx_ptr, (*map)->window_ptr);
	if ((*map)->mlx_ptr)
	{
		mlx_destroy_display((*map)->mlx_ptr);
		free((*map)->mlx_ptr);
	}
	free(*map);
	*map = NULL;
}

void	exit_error(char *str, t_map *map)
{
	ft_printf("%s\n", str);
	free_map(&map);
	exit(EXIT_FAILURE);
}
