/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:03:47 by dteruya           #+#    #+#             */
/*   Updated: 2025/07/23 19:57:52 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	is_identifier(t_info *info, char *line, int *i)
{
	if (line[*i] == 'S' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		init_south(info, i, line);
	else if (line[*i] == 'E' && line[*i + 1] == 'A' && line[*i + 2] == ' ')
		init_east(info, i, line);
	else if (line[*i] == 'W' && line[*i + 1] == 'E' && line[*i + 2] == ' ')
		init_west(info, i, line);
	else if (line[*i] == 'N' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		init_north(info, i, line);
	else if ((line[*i] == 'F' || line[*i] == 'C') && line[*i + 1] == ' ')
		init_rgb(info, line);
}

static void inittttt(t_info *info)
{
	info->east_texture = NULL;
	info->west_texture = NULL;
	info->south_texture = NULL;
	info->north_texture = NULL;
	info->floor_color[0] = -1;
	info->ceiling_color[0] = -1;
}

void	init_info(char *file_name, t_info **info)
{
	int		fd;
	char	*line;
	int		i;

	*info = ft_calloc(1, sizeof(t_info));
	inittttt(*info);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_and_exit("Error: opening file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (is_wspace(line[i]))
			i++;
		is_identifier(*info, line, &i);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
