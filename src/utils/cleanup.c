/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:10:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/24 03:00:12 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_info(t_info *info)
{
	if (info->north_texture)
		free(info->north_texture);
	if (info->south_texture)
		free(info->south_texture);
	if (info->west_texture)
		free(info->west_texture);
	if (info->east_texture)
		free(info->east_texture);
	free(info);
	info = NULL;
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
	matrix = NULL;
}

void	free_map(t_map *map)
{
	if (map->matrix)
		free_matrix(map->matrix, map->rows_amount);
	if (map->pov)
		free(map->pov);
	free(map);
	map = NULL;
}

bool	is_wspace(char input)
{
	if (input == ' ' || input == '\t')
		return (true);
	return (false);
}

void	exit_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
