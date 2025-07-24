/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:16:13 by diego             #+#    #+#             */
/*   Updated: 2025/07/24 02:55:11 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	flood_fill_recursive(t_map **map, int **map_copy, int x, int y)
{
	if (y < 0 || y >= (*map)->rows_amount || x < 0 || x >= (*map)->cols_amount)
		return (true);
	if (map_copy[y][x] == WALL_VALUE || map_copy[y][x] == VISITED_VALUE)
		return (true);
	if (map_copy[y][x] == 2)
	{
		ft_printf("Error: Map leak - flood hit an 'outside'");
		ft_printf("or invalid area (value 2) at (%d, %d)\n", x, y);
		return (false);
	}
	map_copy[y][x] = VISITED_VALUE;
	if (!flood_fill_recursive(map, map_copy, x + 1, y)
		|| !flood_fill_recursive(map, map_copy, x - 1, y)
		|| !flood_fill_recursive(map, map_copy, x, y + 1)
		|| !flood_fill_recursive(map, map_copy, x, y - 1))
		return (false);
	return (true);
}

static bool	prepare_and_validate_fill(t_map *map, int ***temp_map_ptr)
{
	t_point	player_start_copy;

	*temp_map_ptr = dup_int_matrix(map);
	if (!*temp_map_ptr)
		return (false);
	player_start_copy = *map->pov;
	if (player_start_copy.x < 0 || player_start_copy.x >= map->cols_amount
		|| player_start_copy.y < 0 || player_start_copy.y >= map->rows_amount)
	{
		free_matrix(*temp_map_ptr, map->rows_amount);
		printf("Error: Player start position is out of map bounds.\n");
		return (false);
	}
	flood_fill_recursive(&map, *temp_map_ptr,
		player_start_copy.x, player_start_copy.y);
	return (true);
}

static bool	validate_map_cell(int **temp_map, int y, int x, t_point map_size)
{
	if (y == 0 || y == map_size.y - 1 || x == 0 || x == map_size.x - 1)
	{
		if (temp_map[y][x] == VISITED_VALUE)
		{
			ft_printf("Error: Map border leak detected at (%d, %d).\n", x, y);
			printf("Map is not enclosed by walls!\n");
			return (false);
		}
	}
	else if (temp_map[y][x] == EMPTY_VALUE)
	{
		ft_printf("Error: Unreachable empty ");
		ft_printf("space detected at (%d, %d).\n", x, y);
		printf("Map contains unreachable empty spaces!\n");
		return (false);
	}
	return (true);
}

static bool	check_filled_map_integrity(t_map *map_data, int **temp_map)
{
	int		y_idx;
	int		x_idx;
	t_point	map_size;

	map_size.y = map_data->rows_amount;
	map_size.x = map_data->cols_amount;
	y_idx = 0;
	while (y_idx < map_size.y)
	{
		x_idx = 0;
		while (x_idx < map_size.x)
		{
			if (!validate_map_cell(temp_map, y_idx, x_idx, map_size))
			{
				free_matrix(temp_map, map_data->rows_amount);
				return (false);
			}
			x_idx++;
		}
		y_idx++;
	}
	return (true);
}

bool	flood_fill_validation(t_map **map)
{
	int	**temp_map;

	if (!prepare_and_validate_fill(*map, &temp_map))
		return (false);
	if (!check_filled_map_integrity(*map, temp_map))
		return (false);
	free_matrix(temp_map, (*map)->rows_amount);
	return (true);
}
