/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:37 by diego             #+#    #+#             */
/*   Updated: 2025/07/24 15:41:44 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static bool	is_empty_map(char *file_name)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_only_wspace(line))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count <= 6)
		return (true);
	return (false);
}

static bool	count_letters(t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < map->rows_amount)
	{
		j = 0;
		while (j < map->cols_amount)
		{
			if (map->matrix[i][j] > 3)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

bool	is_valid_map(char *file_name, t_map **map, t_info **info)
{
	if (is_empty_map(file_name))
	{
		printf("DEBUG: Não tem mapa\n");
		return (false);
	}
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (false);
	init_matrix(file_name, *map);
	if (!count_letters(*map))
	{
		printf("TEM ZERO SPAWNS\n");
		return (false);
	}
	(*map)->info = *info;
	return (flood_fill_validation(map));
}
