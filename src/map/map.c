/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:37 by diego             #+#    #+#             */
/*   Updated: 2025/07/23 20:43:40 by dteruya          ###   ########.fr       */
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

void    flood_fill_recursive(t_map *data, int **map_copy, int x, int y)
{
	if (y < 0 || y >= data->rows_amount || x < 0 || x >= data->cols_amount)
	{
		return ;
	}
	if (map_copy[y][x] == WALL_VALUE || map_copy[y][x] == VISITED_VALUE)
		return ;
	if (map_copy[y][x] == 2)
	{
		fprintf(stderr, "Error: Map leak - flood hit an 'outside' or invalid area (value 2) at (%d, %d)\n", x, y);
		exit(EXIT_FAILURE);
	}
	if (map_copy[y][x] != EMPTY_VALUE) {

	}
	map_copy[y][x] = VISITED_VALUE;
	flood_fill_recursive(data, map_copy, x + 1, y);
	flood_fill_recursive(data, map_copy, x - 1, y);
	flood_fill_recursive(data, map_copy, x, y + 1);
	flood_fill_recursive(data, map_copy, x, y - 1);
}

// static void	fill_the_copy(char *file_name, int *map)
// {
// 	int		fd;
// 	int		count;
// 	int		i;
// 	char	*line;

// 	i = 7;
// 	count = 0;
// 	fd = open(file_name, O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		if (!is_only_wspace(line))
// 			count++;
// 		if (count > 6)
// 			insert_the_values(line, map, count - i);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }

// int **dup_int_matrix(int **original_matrix, int rows, int cols)
// {
// 	int **copy_matrix;
// 	int i;
// 	int j;

// 	i = 0;
// 	copy_matrix = (int **)malloc(sizeof(int *) * rows);
// 	if (!copy_matrix)
// 	{
// 		fprintf(stderr, "Error: Memory allocation failed for matrix rows in dup_int_matrix.\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	while (i < rows)
// 	{
// 		j = 0;
// 		while (j < cols)
// 		{
// 			copy_matrix[i][j] = original_matrix[i][j];
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (copy_matrix);
// }


int **dup_int_matrix(int **original_matrix, int rows, int cols)
{
	int **copy_matrix;
	int i;
	int j;

	copy_matrix = (int **)malloc(sizeof(int *) * rows);
	if (!copy_matrix)
	{
		fprintf(stderr, "Error: Memory allocation failed for matrix rows in dup_int_matrix.\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < rows)
	{
		copy_matrix[i] = (int *)malloc(sizeof(int) * cols);
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
		j = 0;
		while (j < cols)
		{
			copy_matrix[i][j] = original_matrix[i][j];
			j++;
		}
		i++;
	}
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

void flood_fill_validation(t_map *data)
{
    int     **temp_map;
    t_point map_size;
    t_point player_start_copy;
    int     y_idx;
    int     x_idx;
    int     k_idx;

    temp_map = dup_int_matrix(data->matrix, data->rows_amount, data->cols_amount);
	printf("%d\n%d\n", data->pov->x, data->pov->y);
    player_start_copy = *data->pov;
	printf("KKKKKKK\n");
    if (player_start_copy.x < 0 || player_start_copy.x >= data->cols_amount ||
        player_start_copy.y < 0 || player_start_copy.y >= data->rows_amount)
    {
        // Free temp_map if it was successfully allocated before exiting.
        k_idx = 0;
        while (k_idx < data->rows_amount) {
            free(temp_map[k_idx]);
            k_idx++;
        }
        free(temp_map);
        printf("Error: Player start position is out of map bounds.");
    }
	printf("NÂO FOI AQUI HEIN\n");
    // Convert player character value to an empty space (0) for the flood fill.
    // Assuming player values are > 2 (e.g., 78 for 'N').
    if (temp_map[player_start_copy.y][player_start_copy.x] >= 69) // Lowest player char value from dg_strcmp
    {
         temp_map[player_start_copy.y][player_start_copy.x] = EMPTY_VALUE;
    }
    else
    {
        // If the player's starting position in the matrix is not a recognized player character value (e.g., it's a wall or empty)
        // This indicates an error in map parsing or player position determination.
        k_idx = 0;
        while (k_idx < data->rows_amount) {
            free(temp_map[k_idx]);
            k_idx++;
        }
        free(temp_map);
        printf("Error: Player start position in map matrix is not a valid player character value.");
    }

    map_size.x = data->cols_amount;
    map_size.y = data->rows_amount;

    // Step 4: Start the recursive flood fill from the player's position on the copied map.
    flood_fill_recursive(data, temp_map, player_start_copy.x, player_start_copy.y);

    // Step 5: After the fill, check the *copied* map for leaks and unreachable areas.
    y_idx = 0;
    while (y_idx < map_size.y) // Outer loop for rows
    {
        x_idx = 0;
        while (x_idx < map_size.x) // Inner loop for columns
        {
            // Check 5a: Border cells for unvisited empty spaces or visited non-walls (leaks).
            // A leak occurs if an EMPTY_VALUE (0) or a VISITED_VALUE (9) is found on the border.
            if (y_idx == 0 || y_idx == map_size.y - 1 || x_idx == 0 || x_idx == map_size.x - 1)
            {
                if (temp_map[y_idx][x_idx] == EMPTY_VALUE || temp_map[y_idx][x_idx] == VISITED_VALUE)
                {
                    fprintf(stderr, "Error: Map border leak detected at (%d, %d).\n", x_idx, y_idx);
                    // Free temp_map before exiting on error.
                    k_idx = 0;
                    while (k_idx < map_size.y) {
                        free(temp_map[k_idx]);
                        k_idx++;
                    }
                    free(temp_map);
                    printf("Map is not enclosed by walls!");
                }
            }
            // Check 5b: Unreachable empty spaces *inside* the map.
            // If an EMPTY_VALUE (0) is found anywhere *not* on the border, and it wasn't visited,
            // it means there's an unreachable empty space.
            else if (temp_map[y_idx][x_idx] == EMPTY_VALUE)
            {
                fprintf(stderr, "Error: Unreachable empty space detected at (%d, %d).\n", x_idx, y_idx);
                // Free temp_map before exiting on error.
                k_idx = 0;
                while (k_idx < map_size.y) {
                    free(temp_map[k_idx]);
                    k_idx++;
                }
                free(temp_map);
                printf("Map contains unreachable empty spaces!");
            }
            // Check 5c: If any '2' (invalid/outside map value) remains in the map *and* was not visited.
            // This case depends on how strictly '2' is handled. If it means "outside world that should be walled off,"
            // and it wasn't visited (so not a leak through it) but still present, it might be an issue.
            // The `flood_fill_recursive` now exits immediately if it hits a '2', so this specific `else if` might be redundant for '2' values.
            // If `2`s are allowed *outside* the playable area, but should not be *reachable*, the recursive function's immediate exit on '2' handles it.
            // This part is mainly for any other *unvisited* values that are not walls or empty.
            x_idx++;
        }
        y_idx++;
    }

    // Step 6: If all checks pass, the map is valid according to flood fill.
    // Free the duplicated map.
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
	flood_fill_validation(*map);
	return (true);
}
