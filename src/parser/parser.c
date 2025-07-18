/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:54:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/17 21:06:11 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_valid_argc(int argc)
{
	if (argc == 2)
		return (true);
	else
		return (false);
}

bool	parse_input(int ac, char **av)
{
	char	*file_name;
	t_info	*info;

	info = NULL;
	file_name = av[1];
	if (!is_valid_argc(ac))
	{
		printf("%s", INVALID_ARGC);
		return (false);
	}
	if (!is_valid_extension(file_name))
	{
		printf("%s", FORMAT);
		return (false);
	}
	if (!is_valid_file(file_name, info))
	{
		// free_info(info);
		printf("%s", MAP);
		return (false);
	}
	// free(info);
	return (true);
}
