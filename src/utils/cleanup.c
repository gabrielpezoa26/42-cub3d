/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:10:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/23 18:57:19 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_info(t_maṕ *info)
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
}

static void	free_matrix(int **matrix, int height)
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

void	free_map(t_map *map)
{
	if (map->matrix)
		free_matrix(map->matrix, map->rows_amount);
	free(map);
}

void	free_array(void **tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

bool	is_wspace(char input)
{
	if (input == ' ' || input == '\t')
		return (true);
	return (false);
}
