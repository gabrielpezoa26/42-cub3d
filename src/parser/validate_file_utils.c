/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:50:23 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/17 15:56:31 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//ve se o arquivo existe msm, ve a extensao .xpm etc. dps se tiver tudo certo,
// passa e joga pros struct
bool parse_textures(t_map *map, int fd)
{
	char *line;
	int	i;

	(void)map;
	line = get_next_line(fd);
	i = 0;
	// while(i < ft_strlen(line))
	// {
		
	// 	i++;
	// }
	printf("DEBUG:  %s\n", line);
	return (true);
}

static bool	mango_loko(char *line)
{
	int		i;

	i = 0;
	while (is_wspace(line[i]))
		i++;
	if (line[i] == 'S' && line[i+1] == 'O' && line[i+2] == ' ')
		return (true);
	else if (line[i] == 'E' && line[i+1] == 'A' && line[i+2] == ' ')
		return (true);
	else if (line[i] == 'W' && line[i+1] == 'E' && line[i+2] == ' ')
		return (true);
	else if (line[i] == 'N' && line[i+1] == 'O' && line[i+2] == ' ')
		return (true);
	else if ((line[i] == 'F' || line[i] == 'C') && line[i+1] == ' ')
		return (true);
	return (false);
}

bool is_only_wspace(char *line)
{
	int i;

	i = 0;
	while(is_wspace(line[i]))
		i++;
	if (line[i] == '\n')
		return (true);
	return (false);
}

bool map_before(char *file_name)
{
	char	*line;
	int		count;
	bool	flag;
	int		fd;
	
	flag = true;
	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_and_exit("Error opening file");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line != '\n' && !is_only_wspace(line))
		{
			if (mango_loko(line))
				count++;
			else if (!(mango_loko(line)) && count != 6)
				flag = false;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (flag);
}


//ve se eh tudo numero, se eh RGB (< 255), etc
// bool parse_colors(t_map *map)
// {
	
// }

// aqui valida a parte dos numeros, se ta fechado, se so tem uma letra WASD, etc
// bool parse_map(t_map *map)
// {
// 
// }

void	print_and_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
