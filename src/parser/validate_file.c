/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:46:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/14 15:41:08 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	validate_file(char **av)
{
	int		fd;
	t_map	*map;

	fd = open(av[1], O_RDONLY, 0777);
	if (!fd)
		printf("Error opening file\n");
	map = malloc(sizeof(t_map));
	if (!map)
	{
		printf("vishhh\n");
		return (false);
	}
	if (!parse_textures(map))
		return (false);
	// if (!parse_map(map))
	// 	return (false);
	return (true);
}

