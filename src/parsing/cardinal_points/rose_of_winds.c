/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rose_of_winds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:33:36 by dteruya           #+#    #+#             */
/*   Updated: 2025/07/25 15:27:30 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_south(t_info *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->south_path)
		return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/so.xpm", 15) != 0)
	{
		print_and_exit("Error in south!");
		free(value);
		return ;
	}
	info->south_path = value;
	if (!info->south_path)
		print_and_exit("Error in south!");
	info->south_path = value;
}

void	init_east(t_info *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->east_path)
		return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/ea.xpm", 15) != 0)
	{
		print_and_exit("Error in east!");
		free(value);
		return ;
	}
	info->east_path = value;
	if (!info->east_path)
		print_and_exit("Error in east!");
	info->east_path = value;
}

void	init_west(t_info *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->west_path)
		return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/we.xpm", 15) != 0)
	{
		print_and_exit("Error in west!");
		free(value);
		return ;
	}
	info->west_path = value;
	if (!info->west_path)
		print_and_exit("Error in west!");
	info->west_path = value;
}

void	init_north(t_info *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->north_path)
		return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/no.xpm", 15) != 0)
	{
		print_and_exit("Error in north!");
		free(value);
		return ;
	}
	info->north_path = value;
	if (!info->north_path)
		print_and_exit("Error in norht!");
	info->north_path = value;
}
