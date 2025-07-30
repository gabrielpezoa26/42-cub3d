/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:43 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/30 14:45:35 by gcesar-n         ###   ########.fr       */
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

static bool	game_loop(t_map *map)
{
	(void)map;
	printf("DEBUG: entering game_loop() \n");
	// mlx_loop(map->mlx_ptr);
	// seta os controles
	// da free em tudo
	printf("DEBUG: game_loop() -> finished\n");
	return (true);
}

static void	execution(t_map *map)
{
	init_graphics(map);
	init_textures(map);
	init_player(map);
	game_loop(map);
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
