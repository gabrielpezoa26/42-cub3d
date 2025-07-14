/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:46:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/14 17:42:02 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_valid_file(char **av)
{
	int		fd;
	t_map	*map;

	fd = open(av[0], O_RDONLY);
	if (fd == -1)
		printf("Error opening file\n");
	map = malloc(sizeof(t_map));
	if (!map)
	{
		printf("vishhh\n");
		return (false);
	}
	if (!parse_textures(map, fd))
		return (false);
	// if (!parse_map(map))
	// 	return (false);
	// if (!parse_colors(map))
	// 	return (false);
	return (true);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }