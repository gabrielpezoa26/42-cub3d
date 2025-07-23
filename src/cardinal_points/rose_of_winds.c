/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rose_of_winds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:33:36 by dteruya           #+#    #+#             */
/*   Updated: 2025/07/23 18:57:19 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_south(t_maṕ *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->south_texture)
			return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/so.xpm", 15) != 0)
	{
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->south_texture = value;
	if (!info->south_texture)
		print_and_exit("Error!");
	info->south_texture = value;
	printf("DEBUG: value malokado:  %s\n", info->south_texture);
}

void	init_east(t_maṕ *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->east_texture)
			return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/ea.xpm", 15) != 0)
	{
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->east_texture = value;
	if (!info->east_texture)
		print_and_exit("Error!");
	info->east_texture = value;
	printf("DEBUG: value malokado:  %s\n", info->east_texture);
}

void	init_west(t_maṕ *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->west_texture)
			return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/we.xpm", 15) != 0)
	{
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->west_texture = value;
	if (!info->west_texture)
		print_and_exit("Error!");
	info->west_texture = value;
	printf("DEBUG: value malokado:  %s\n", info->west_texture);
}

void	init_north(t_maṕ *info, int *i, char *line)
{
	int		j;
	char	*value;

	*i = *i + 2;
	while (is_wspace(line[*i]))
		(*i)++;
	j = *i;
	while (!is_wspace(line[*i]) && line[*i] != '\n')
		(*i)++;
	if (info->north_texture)
			return ;
	value = ft_substr(line, j, *i - j);
	if (ft_strncmp(value, "./assets/no.xpm", 15) != 0)
	{
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->north_texture = value;
	if (!info->north_texture)
		print_and_exit("Error!");
	info->north_texture = value;
	printf("DEBUG: value malokado:  %s\n", info->north_texture);
}
