/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:37 by diego             #+#    #+#             */
/*   Updated: 2025/07/23 18:59:53 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

// static bool	is_too_small()
// {
	
// }

// void	flood_fill(t_maṕ *info, char **map, int x, int y)
// {
// 	if (y < 0 || y >= info->
// 		|| x < 0 || x >= (int)ft_strlen(map[y]))
// 	{
// 		fprintf(stderr, "Flood fill escaped at (%d, %d)\n", x, y);
// 		error_exit("Map leak: flood escaped the map!", info);
// 	}
// 	if (map[y][x] == '1' || map[y][x] == 'F')
// 		return ;
// 	if (map[y][x] == ' ')
// 		error_exit("Map leak: flood hit open space!", info);
// 	if (!ft_strchr("0NSEW", map[y][x]))
// 		return ;
// 	map[y][x] = 'F';
// 	flood_fill(info, map, x + 1, y);
// 	flood_fill(info, map, x - 1, y);
// 	flood_fill(info, map, x, y + 1);
// 	flood_fill(info, map, x, y - 1);
// }

// char	**dup_map(t_maṕ *data)
// {
// 	char	**copy;
// 	int		i;

// 	copy = ft_calloc(data->map_height + 1, sizeof(char *));
// 	i = 0;
// 	if (!copy)
// 		error_exit("Memory failed during flood fill", data);
// 	while (i < data->map_height)
// 	{
// 		copy[i] = ft_strdup(data->map[i]);
// 		i++;
// 	}
// 	return (copy);
// }
static bool count_letters(t_map *map)
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
			if (map->matrix[i][j] > 2)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

bool	is_valid_map(char *file_name, t_map **map)
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
	// if (is_too_small(matrix))
	return (true);
}
