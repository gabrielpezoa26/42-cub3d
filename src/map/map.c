/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:31:37 by diego             #+#    #+#             */
/*   Updated: 2025/07/22 22:28:07 by diego            ###   ########.fr       */
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
	// if (is_too_small(matrix))
	return (true);
}
