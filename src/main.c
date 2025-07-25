/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:43 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/25 16:53:07 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

bits_por_pixel, tamanho_da_linha e endian.


int	main(int ac, char **av)
{
	t_info	*info;
	t_map	*map;

	int floor_color_int;
	int ceiling_color_int;
	
	info = NULL;
	map = NULL;
	if (!parse_input(ac, av, &info, &map))
		printf("DEBUG: Deu ruim no mapa\n");
	else
	{
		floor_color_int = rgb_to_int(map->info->floor_color[0], map->info->floor_color[1], map->info->floor_color[2]);
		ceiling_color_int = rgb_to_int(map->info->ceiling_color[0], map->info->ceiling_color[1], map->info->ceiling_color[2]);
		printf("DEBUG: Cor do chão convertida para o inteiro: %d\n", floor_color_int);
		printf("DEBUG: Cor do teto convertida para o inteiro: %d\n", ceiling_color_int);
		map->mlx_ptr = mlx_init();
		map->window_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, TITLE);
		map->img_ptr = mlx_new_image(map->window_ptr, WIDTH, HEIGHT);
		
		load_textures(map);
		// abre_tela();
		printf("DEBUG: finish\n");
	}
	if (map)
		free_map(&map);
	return (0);
}
