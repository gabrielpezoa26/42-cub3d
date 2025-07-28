/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:43 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/28 18:17:42 by gcesar-n         ###   ########.fr       */
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

	map->mangoloko = ft_calloc(1, sizeof(t_data_img));
	if (!map->mangoloko)
		exit_error("Error allocating memory for main image struct\n", map);

	map->mangoloko->img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->mangoloko->addr = mlx_get_data_addr(map->mangoloko->img_ptr,
			&map->mangoloko->bits_per_pixel,
			&map->mangoloko->line_length, &map->mangoloko->endian);
	printf("DEBUG: deu boa\n");
	load_textures(map);
	printf("DEBUG: execution() -> finish\n");
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
	printf("DEBUG: main() -> finish\n");
	return (0);
}
