/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:43 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/03 19:07:24 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_graphics(t_map *map)
{
	init_texture_struct(map);
	init_data_img(map);
	map->mlx_ptr = mlx_init();
	map->window_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, TITLE);
	map->img->img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->img->addr = mlx_get_data_addr(map->img->img_ptr,
			&map->img->bits_per_pixel,
			&map->img->line_length, &map->img->endian);
	printf("DEBUG: init_graphics()-> finished\n");
}

// static void	execution(t_map *map)
// {
// 	init_graphics(map);
// 	init_textures(map);
// 	init_player(map);
// 	mlx_loop_hook(map->mlx_ptr, render, map); // game é sua struct principal
// 	mlx_loop(map->mlx_ptr); // Inicia o loop da minilibx
// 	printf("DEBUG: execution() -> finished\n");
// }

static void execution(t_map *map)
{
	init_graphics(map);
	init_textures(map);
	init_player(map);
	mlx_key_hook(map->window_ptr, key_hook, map);
	mlx_hook(map->window_ptr, 17, 0, close_game, map);
	mlx_loop_hook(map->mlx_ptr, render, map);
	mlx_loop(map->mlx_ptr);
	printf("DEBUG: execution() -> finished\n");
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
	printf("DEBUG: main() -> finish :)) \n");
	return (0);
}
