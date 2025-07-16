/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:46:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/16 20:11:41 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool is_empty(char *file_name)
{
	bool	flag;
	char	*str;
	int		fd;

	flag = true;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_and_exit("Error opening file");
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (!is_only_wspace(str))
			flag = false;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (flag);
}

bool	is_valid_file(char *file_name, t_info *info)
{
	// t_map	*map;

	if (is_empty(file_name))
		return (false);
	if (!map_before(file_name))
		return (false);
	init_info(file_name, info);
/*	if (!parse_textures(fd))
		exit = false;
	if (!parse_map(map))
		exit = false;
	if (!parse_colors(map))
		exit = false;*/
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