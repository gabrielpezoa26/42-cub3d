/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:37 by diego             #+#    #+#             */
/*   Updated: 2025/07/23 23:43:05 by diego            ###   ########.fr       */
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

void	flood_fill_recursive(t_map **map, int **map_copy, int x, int y)
{
	if (y < 0 || y >= (*map)->rows_amount || x < 0 || x >= (*map)->cols_amount)
		return ;
	printf("%d", map_copy[x][y]);
	if (map_copy[x][y] == WALL_VALUE || map_copy[x][y] == VISITED_VALUE)
		return ;
	printf("Até aqui foi\n");
	if (map_copy[x][y] == 2)
	{
		fprintf(stderr, "Error: Map leak - flood hit an 'outside' or invalid area (value 2) at (%d, %d)\n", x, y);
		exit(EXIT_FAILURE);
	}
	map_copy[x][y] = VISITED_VALUE;
	flood_fill_recursive(map, map_copy, x + 1, y);
	flood_fill_recursive(map, map_copy, x - 1, y);
	flood_fill_recursive(map, map_copy, x, y + 1);
	flood_fill_recursive(map, map_copy, x, y - 1);
}

int **dup_int_matrix(int **original_matrix, int rows, int cols)
{
	int **copy_matrix;
	int i;
	int j;

	copy_matrix = ft_calloc(1, sizeof(int *) * rows);
	if (!copy_matrix)
	{
		fprintf(stderr, "Error: Memory allocation failed for matrix rows in dup_int_matrix.\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < rows)
	{
		copy_matrix[i] = calloc(1, sizeof(int) * cols);
		if (!copy_matrix[i])
		{
			j = 0;
			while (j < i)
			{
				free(copy_matrix[j]);
				j++;
			}
			free(copy_matrix);
			fprintf(stderr, "Error: Memory allocation failed for matrix columns in dup_int_matrix.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			copy_matrix[i][j] = original_matrix[i][j];
			j++;
		}
		i++;
	}
	print_matrix(copy_matrix, rows, cols);
	return (copy_matrix);
}

void init_map_matrix_allocation(t_map *map)
{
	int i;

	map->matrix = (int **)ft_calloc(map->rows_amount, sizeof(int *));
	if (!map->matrix)
	{
		perror("Memory allocation failed for map matrix (rows)");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->rows_amount)
	{
		map->matrix[i] = (int *)ft_calloc(map->cols_amount, sizeof(int));
		if (!map->matrix[i])
		{
			perror("Memory allocation failed for map matrix (columns)");
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

void flood_fill_validation(t_map **map)
{
    int     **temp_map;
    t_point map_size;
    t_point player_start_copy;
    int     y_idx;
    int     x_idx;
    int     k_idx;

    temp_map = dup_int_matrix((*map)->matrix, (*map)->rows_amount, (*map)->cols_amount);
    player_start_copy = *(*map)->pov;
    if (player_start_copy.x < 0 || player_start_copy.x >= (*map)->cols_amount ||
        player_start_copy.y < 0 || player_start_copy.y >= (*map)->rows_amount)
    {
        k_idx = 0;
        while (k_idx < (*map)->rows_amount) {
            free(temp_map[k_idx]);
            k_idx++;
        }
        free(temp_map);
        printf("Error: Player start position is out of map bounds.");
    }
    map_size.y = (*map)->cols_amount;
    map_size.x = (*map)->rows_amount;
    flood_fill_recursive(map, temp_map, player_start_copy.x, player_start_copy.y);
    x_idx = 0;
    while (y_idx < map_size.x)
    {
        y_idx = 0;
        while (y_idx < map_size.x)
        {
            if (y_idx == 0 || y_idx == map_size.y - 1 || x_idx == 0 || x_idx == map_size.x - 1)
            {
                if (temp_map[x_idx][y_idx] == EMPTY_VALUE || temp_map[x_idx][y_idx] == VISITED_VALUE)
                {
                    fprintf(stderr, "Error: Map border leak detected at (%d, %d).\n", x_idx, y_idx);
                    k_idx = 0;
                    while (k_idx < map_size.x)
					{
                        free(temp_map[k_idx]);
                        k_idx++;
                    }
                    free(temp_map);
                    printf("Map is not enclosed by walls!");
                }
            }
            else if (temp_map[x_idx][y_idx] == EMPTY_VALUE)
            {
                fprintf(stderr, "Error: Unreachable empty space detected at (%d, %d).\n", x_idx, y_idx);
                k_idx = 0;
                while (k_idx < map_size.y) {
                    free(temp_map[k_idx]);
                    k_idx++;
                }
                free(temp_map);
                printf("Map contains unreachable empty spaces!");
            }
            y_idx++;
        }
        x_idx++;
    }
    k_idx = 0;
    while (k_idx < map_size.y)
    {
        free(temp_map[k_idx]);
        k_idx++;
    }
    free(temp_map);
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
	flood_fill_validation(map);
	return (true);
}
