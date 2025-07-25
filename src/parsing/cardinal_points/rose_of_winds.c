/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rose_of_winds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:33:36 by dteruya           #+#    #+#             */
/*   Updated: 2025/07/24 21:16:19 by diego            ###   ########.fr       */
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
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->south_path = value;
	if (!info->south_path)
		print_and_exit("Error!");
	info->south_path = value;
	printf("DEBUG: value malokado:  %s\n", info->south_path);
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
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->east_path = value;
	if (!info->east_path)
		print_and_exit("Error!");
	info->east_path = value;
	printf("DEBUG: value malokado:  %s\n", info->east_path);
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
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->west_path = value;
	if (!info->west_path)
		print_and_exit("Error!");
	info->west_path = value;
	printf("DEBUG: value malokado:  %s\n", info->west_path);
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
		print_and_exit("Error!");
		free(value);
		return ;
	}
	printf("\nDEBUG: value antes malloc: %s\n", value);
	info->north_path = value;
	if (!info->north_path)
		print_and_exit("Error!");
	info->north_path = value;
	printf("DEBUG: value malokado:  %s\n", info->north_path);
}
