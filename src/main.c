/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:43 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/26 19:34:59 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_textures(t_map *map)
{
	map->text = ft_calloc(1, sizeof(t_texture));
	if (!map->text)
		exit_error("Error allocating memory for textures struct\n", map);
}

static void	execution(t_map *map)
{
	int	floor_color;
	int	ceiling_color;

	floor_color = rgb_to_int(map->info->floor_color[0],
			map->info->floor_color[1], map->info->floor_color[2]);
	ceiling_color = rgb_to_int(map->info->ceiling_color[0],
			map->info->ceiling_color[1], map->info->ceiling_color[2]);
	printf("DEBUG: Cor do chão convertida: %d\n", floor_color);
	printf("DEBUG: Cor do teto convertida: %d\n", ceiling_color);
	init_textures(map);
	map->mlx_ptr = mlx_init();
	map->window_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, TITLE);
	map->img_ptr = mlx_new_image(map->window_ptr, WIDTH, HEIGHT);
	load_textures(map);
	printf("DEBUG: finish\n");
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_map	*map;

	info = NULL;
	map = NULL;
	if (!parse_input(ac, av, &info, &map))
		printf("DEBUG: Deu ruim no mapa\n");
	else
	{
		execution(map);
	}
	if (map)
		free_map(&map);
	return (0);
}
