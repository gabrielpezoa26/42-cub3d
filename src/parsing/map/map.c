/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:37 by diego             #+#    #+#             */
/*   Updated: 2025/07/29 20:13:09 by gcesar-n         ###   ########.fr       */
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
		printf("Error: Map is empty.\n");
		return (false);
	}
	*map = ft_calloc(1, sizeof(t_map));
	if (!*map)
		return (false);
	(*map)->info = *info;
	init_matrix(file_name, *map);
	if (!count_letters(*map))
	{
		printf("Error: TEM ZERO SPAWNS\n");
		return (false);
	}
	if (!flood_fill_validation(map))
	{
		printf("Error: Map is not enclosed by walls.\n");
		return (false);
	}
	return (true);
}
