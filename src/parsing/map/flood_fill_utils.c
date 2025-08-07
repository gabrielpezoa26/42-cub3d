/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:50:12 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/07 17:47:35 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	init_matrix_copy(int **copy_matrix, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows_amount)
	{
		j = 0;
		while (j < map->cols_amount)
		{
			copy_matrix[i][j] = map->matrix[i][j];
			j++;
		}
		i++;
	}
}

int	**dup_int_matrix(t_map *map)
{
	int	**copy_matrix;
	int	i;
	int	j;

	i = 0;
	copy_matrix = ft_calloc(map->rows_amount, sizeof(int *));
	if (copy_matrix == NULL)
		exit_error("Memory allocation failed for matrix", map);
	while (i < map->rows_amount)
	{
		copy_matrix[i] = ft_calloc(map->cols_amount, sizeof(int));
		if (copy_matrix[i] == NULL)
		{
			perror("Memory allocation failed for matrix");
			j = 0;
			while (j < i)
				free(copy_matrix[j++]);
			free(copy_matrix);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	init_matrix_copy(copy_matrix, map);
	return (copy_matrix);
}
