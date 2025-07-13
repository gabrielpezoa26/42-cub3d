/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:46:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/13 01:16:16 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// bool	parse_file(char **av)
// {
// 	int		fd;
// 	t_map	*map;
	
// 	fd = open(av[1], O_RDONLY, 0777);
// 	if (!fd)
// 		printf("vishh\n");
// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 	{
// 		printf("vishhh\n")
// 		return (false);
// 	}
// }

//          FDF
// static t_map	*input_parser(char *filename)
// {
// 	int		fd;
// 	t_map	*map;

// 	fd = open(filename, O_RDONLY, 0777);
// 	if (fd == -1)
// 		handle_error("Error");
// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 	{
// 		close(fd);
// 		handle_error("Malloc fail");
// 	}
// 	map_init(map);
// 	get_map_size(fd, map);
// 	close(fd);
// 	allocate_map(map);
// 	map->interval = ft_min(WIDTH / map->cols, HEIGHT / map->rows) / 2;
// 	map->interval = ft_max(2, map->interval);
// 	fd = open(filename, O_RDONLY, 0777);
// 	map_parser(fd, map);
// 	close(fd);
// 	return (map);
// }
