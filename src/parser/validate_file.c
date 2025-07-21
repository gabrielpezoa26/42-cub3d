/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:46:41 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/21 13:42:53 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	bool is_empty(char *file_name)
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

static bool	verify_info(t_info *info)
{
	if (!info->south_texture)
	{
		printf("DEBUG: dasdsadsa\n");
		return (false);
	}
	if (!info->west_texture)
		return (false);
	if (!info->east_texture)
		return (false);
	if (!info->north_texture)
		return (false);
	// if (*info->floor_color == -1)
	// {
	// 	printf("floor color deu ruim \n");
	// 	return (false);
	// }
	// if (*info->ceiling_color == -1)
	// {
	// 	printf("ceiling color deu ruim \n");
	// 	return (false);
	// }
	return (true);
}

bool	is_valid_file(char *file_name, t_info *info)
{
	if (is_empty(file_name))
		return (false);
	if (!map_before(file_name))
		return (false);
	init_info(file_name, info);
	if (!verify_info(info)) //ta dando b.o aqui rs
	{
		printf("DEBUG: deu ruimmm verify info\n");
		return (false);
	}
	return (true);
}
