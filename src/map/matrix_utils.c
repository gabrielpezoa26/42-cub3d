/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:27:10 by diego             #+#    #+#             */
/*   Updated: 2025/07/22 23:18:59 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*dg_strcmp(char c)
{
	if (ft_strcmp(&c, "0") == 0)
		return ("0");
	else if (ft_strcmp(&c, "1") == 0)
		return ("1");
	else if (ft_strcmp(&c, "N") == 0)
		return ("78");
	else if (ft_strcmp(&c, "S") == 0)
		return ("83");
	else if (ft_strcmp(&c, "W") == 0)
		return ("87");
	else if (ft_strcmp(&c, "E") == 0)
		return ("69");
	else
		return ("\0");
}

static void	insert_the_values(char *line, t_map *map, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (line[j] != '\n' && line[j] != '\0' && j < map->cols_amount)
	{
		tmp = ft_strdup(dg_strcmp(line[j]));
		map->matrix[i][j] = atoi(tmp);
		free(tmp);
		j++;
	}
}

void	fill_the_matrix(char *file_name, t_map *map)
{
	int		fd;
	int		count;
	int		i;
	char	*line;

	i = 7;
	count = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_only_wspace(line))
			count++;
		if (count > 6)
			insert_the_values(line, map, count - i);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
