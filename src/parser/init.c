/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:03:47 by dteruya           #+#    #+#             */
/*   Updated: 2025/07/17 15:09:55 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_south(t_info *info, int *i, char *line)
{
	int	j;
	char *value;

	*i = *i + 2;
	info = ft_calloc(1, sizeof(t_info));
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	value = ft_substr(line, j, *i - j);
	printf("DEBUG: value antes malloc: %s\n", value);
	info->south_texture = malloc(sizeof(char) * ft_strlen(value));
	if (!info->south_texture)
		print_and_exit("Error!");
	info->south_texture = value;
	printf("DEBUG: value malokado:  %s\n", info->south_texture);
	free(value);
}

static void	is_ID(t_info *info, char *line, int *i)
{
	if (line[*i] == 'S' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
	{
		printf("entrouuuu\n");
		init_south(info, i, line);
	}
	// else if (line[*i] == 'E' && line[*(i+1)] == 'A' && line[*(i+2)] == ' ')
	// 	init_east();
	// else if (line[*i] == 'W' && line[*(i+1)] == 'E' && line[*(i+2)] == ' ')
	// 	init_west();
	// else if (line[*i] == 'N' && line[*(i+1)] == 'O' && line[*(i+2)] == ' ')
	// 	init_north();
	// else if ((line[*i] == 'F' || line[*i] == 'C') && line[*(i+1)] == ' ')
	// 	init_cheto();
}

void	init_info(char *file_name, t_info *info)
{
	int		fd;
	char	*line;
	int		i;

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
	close(fd);
}
