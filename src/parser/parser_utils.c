/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:59:31 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/14 13:38:34 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_valid_char(int c)
{
	if (c == 0 || c == 1 || c == 'W' || c == 'A' || c == 'S' || c == 'D')
		return (true);
	else
		return (false);
}

bool	is_valid_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	filename += len - 4;
	return (ft_strncmp(filename, ".cub", 4) == 0);
}
