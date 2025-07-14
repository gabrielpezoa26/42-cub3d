/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:50:23 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/14 17:36:52 by gcesar-n         ###   ########.fr       */
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

//ve se eh tudo numero, se eh RGB (< 255), etc
// bool parse_colors(t_map *map)
// {
	
// }

// aqui valida a parte dos numeros, se ta fechado, se so tem uma letra WASD, etc
// bool parse_map(t_map *map)
// {
// 
// }
