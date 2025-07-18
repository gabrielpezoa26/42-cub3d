/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:18:38 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/18 16:05:55 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static bool	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_wspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]) && !is_wspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	validate_and_convert_components(int *colors, char **rgb_values)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!is_valid_number(rgb_values[i]))
		{
			free_split(rgb_values);
			print_and_exit("Error!\n");
		}
		colors[i] = ft_atoi(rgb_values[i]);
		if (colors[i] < 0 || colors[i] > 255)
		{
			free_split(rgb_values);
			print_and_exit("Error!\n");
		}
	}
}
static void	parse_and_fill_rgb(int *colors, char *line)
{
	char	**rgb_values;
	int		i;

	rgb_values = ft_split(line, ',');
	if (!rgb_values)
		print_and_exit("Error: Malloc fail\n");
	i = 0;
	while (rgb_values[i])
		i++;
	if (i != 3)
	{
		free_split(rgb_values);
		print_and_exit("Error!\n");
	}
	validate_and_convert_components(colors, rgb_values);
	free_split(rgb_values);
}


void	init_rgb(t_info *info, char *line)
{
	char	identifier;
	int		i;

	i = 0;
	while (line[i] && is_wspace(line[i]))
		i++;
	identifier = line[i];
	i++;
	if (identifier == 'F')
	{
		if (info->floor_color[0] != -1)
			print_and_exit("Error!\n");
		parse_and_fill_rgb(info->floor_color, &line[i]);
		printf("DEBUG: F: %d %d %d\n", info->floor_color[0], 
			info->floor_color[1], info->floor_color[2]);
	}
	else if (identifier == 'C')
	{
		if (info->ceiling_color[0] != -1)
			print_and_exit("Error!\n");
		parse_and_fill_rgb(info->ceiling_color, &line[i]);
		printf("DEBUG: F: %d %d %d\n", info->ceiling_color[0], 
			info->ceiling_color[1], info->ceiling_color[2]);
	}
}
