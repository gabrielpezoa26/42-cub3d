/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:21 by diego             #+#    #+#             */
/*   Updated: 2025/07/23 19:53:04 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	ft_malloc(t_map *map)
{
	int	i;

	i = 0;
	map->matrix = ft_calloc(1, sizeof(int *) * (map->rows_amount));
	if (map->matrix == NULL)
	{
		perror("Memory allocation failed for matrix");
		exit(EXIT_FAILURE);
	}
	while (i < map->rows_amount)
	{
		map->matrix[i] = ft_calloc(1, sizeof(int) * (map->cols_amount));
		if (map->matrix[i] == NULL)
		{
			perror("Memory allocation failed for matrix");
			while (i >= 0)
			{
				free(map->matrix[i]);
				i--;
			}
			free(map->matrix);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static int	count_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return(i);
}

static void	verify_length(int *length, char *line)
{
	int	tmp;

	tmp = count_char(line);
	if (tmp > *length)
		*length = tmp;
}

static int	count_width(int *height, char *file_name)
{
	int		fd;
	int		count;
	int		length;
	char	*line;

	count = 0;
	length = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_only_wspace(line))
			count++;
		if (count > 6)
			verify_length(&length, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	*height = count - 6;
	return (length);
}


/* PARA DEBUGAR */
void	print_matrix(int **matrix, int cols, int rows)
{
	int	i;
	int	j;

	if (!matrix)
		return ;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


void	init_matrix(char *file_name, t_map *map)
{
	map->cols_amount = count_width(&map->rows_amount, file_name);
	printf("%d\n", map->cols_amount);
	printf("%d\n", map->rows_amount);
	ft_malloc(map);
	/*
	kkkkkkkkk tem que preencher a matriz
	*/
	fill_the_matrix(file_name, map);
	print_matrix(map->matrix, map->cols_amount, map->rows_amount);
}