/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:54:07 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/12 16:42:13 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	check_argc(int argc)
{
	if (argc == 2)
		return (true);
	else
		return (false);
}

bool	parse_input(int ac, char **av)
{
	if (!check_argc(ac))
	{
		printf("%s", INVALID_ARGC);
		return (false);
	}
	if (!is_valid_extension(av[1]))
	{
		printf("%s", FORMAT);
		return (false);
	}
	return (true);
}
