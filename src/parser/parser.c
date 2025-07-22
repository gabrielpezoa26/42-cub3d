/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:54:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/22 18:50:17 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_valid_argc(int argc)
{
	if (argc == 2)
		return (true);
	printf("%s", INVALID_ARGC);
	return (false);
}

bool	parse_input(int ac, char **av, t_info **info, t_map **map)
{
	if (!is_valid_argc(ac))
		return (false);
	if (!is_valid_extension(av[1]))
	{
		printf("%s", FORMAT);
		return (false);
	}
	if (!is_valid_file(av[1], info))
		return (false);
	if (!is_valid_map(av[1], map))
		return (false);
	return (true);
}
