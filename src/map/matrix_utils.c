/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:27:10 by diego             #+#    #+#             */
/*   Updated: 2025/07/23 18:39:42 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*dg_strcmp(char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	if (ft_strcmp(tmp, "0") == 0)
		return ("0");
	else if (ft_strcmp(tmp, "1") == 0)
		return ("1");
	else if (ft_strcmp(tmp, "N") == 0)
		return ("78");
	else if (ft_strcmp(tmp, "S") == 0)
		return ("83");
	else if (ft_strcmp(tmp, "W") == 0)
		return ("87");
	else if (ft_strcmp(tmp, "E") == 0)
		return ("69");
	else
		return ("2");
}

static void	insert_the_values(char *line, t_map *map, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (j < map->cols_amount)
	{
		if (j >= (int)ft_strlen(line))
			map->matrix[i][j] = 2;
		else
		{
			tmp = ft_strdup(dg_strcmp(line[j]));
			map->matrix[i][j] = ft_atoi(tmp);
			free(tmp);
		}
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
