/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:10:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/24 19:13:23 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_info(t_info *info)
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

static void	free_textures(t_texture *text)
{
	if (!text)
		return ;
	if (text->north)
		mlx_delete_xpm42(text->north);
	if (text->south)
		mlx_delete_xpm42(text->south);
	if (text->east)
		mlx_delete_xpm42(text->east);
	if (text->west)
		mlx_delete_xpm42(text->west);
	free(text);
}

void	free_map(t_map *map)
{
	if (map->matrix)
		free_matrix(map->matrix, map->rows_amount);
	if (map->pov)
		free(map->pov);
	if (map->info)
		free_info(map->info);
	if (map->text)
		free_textures(map->text);
	if (map->mlx)
		mlx_terminate(map->mlx);
	free(map);
}

void	exit_error(char *str, t_map *map)
{
	ft_printf("%s\n", str);
	free_map(map);
	exit(EXIT_FAILURE);
}
