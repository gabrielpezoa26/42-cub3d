/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:57:21 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/07 17:48:08 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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
	return (i);
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

void	init_matrix(char *file_name, t_map *map)
{
	map->cols_amount = count_width(&map->rows_amount, file_name);
	ft_malloc(map);
	fill_the_matrix(file_name, map);
}
