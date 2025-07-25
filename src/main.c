/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diego <diego@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:43 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/24 18:29:41 by diego            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		map->mlx = mlx_init(800, 600, "OIA A JANELA AÊ", false);
		load_textures(map);
		printf("DEBUG: finish\n");
	}
	if (map)
		free_map(map);
	return (0);
}
