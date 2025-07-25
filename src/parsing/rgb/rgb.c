/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:18:38 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/24 15:42:01 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

static bool	validate_and_convert(int *colors, char **rgb_values)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (!is_valid_number(rgb_values[i]))
			return (ft_putstr_fd("Error!\n", 2), false);
		colors[i] = ft_atoi(rgb_values[i]);
		if (colors[i] < 0 || colors[i] > 255)
			return (ft_putstr_fd("Error!\n", 2), false);
	}
	return (true);
}

static bool	parse_and_fill_rgb(int *colors, char *line)
{
	char	**rgb_values;
	int		i;
	bool	is_valid;

	rgb_values = ft_split(line, ',');
	if (!rgb_values)
		return (ft_putstr_fd("Error: Malloc failed.\n", 2), false);
	i = 0;
	while (rgb_values[i])
		i++;
	if (i != 3)
	{
		free_split(rgb_values);
		return (ft_putstr_fd("Error!\n", 2), false);
	}
	is_valid = validate_and_convert(colors, rgb_values);
	free_split(rgb_values);
	return (is_valid);
}

bool	init_rgb(t_info *info, char *line)
{
	char	identifier;
	int		i;
	bool	flag;

	i = 0;
	while (line[i] && is_wspace(line[i]))
		i++;
	identifier = line[i];
	i++;
	flag = true;
	if (identifier == 'F')
	{
		if (info->floor_color[0] != -1)
			return (ft_putstr_fd("Error!\n", 2), false);
		flag = parse_and_fill_rgb(info->floor_color, &line[i]);
	}
	else if (identifier == 'C')
	{
		if (info->ceiling_color[0] != -1)
			return (ft_putstr_fd("Error!\n", 2), false);
		flag = parse_and_fill_rgb(info->ceiling_color, &line[i]);
	}
	return (flag);
}
