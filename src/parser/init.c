/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:03:47 by dteruya           #+#    #+#             */
/*   Updated: 2025/07/18 15:37:03 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	is_ID(t_info *info, char *line, int *i)
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

void	init_info(char *file_name, t_info *info)
{
	int		fd;
	char	*line;
	int		i;

	info = ft_calloc(1, sizeof(t_info));
	info->floor_color[0] = -1;
	info->ceiling_color[0] = -1;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_and_exit("Error: opening file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (is_wspace(line[i]))
			i++;
		is_ID(info, line, &i);
		free(line);
		line = get_next_line(fd);
	}
	free_info(info);
	free(info);
	close(fd);
}
