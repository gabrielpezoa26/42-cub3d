/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:14:23 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/08/03 21:18:01 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_single_texture(void *mlx_ptr, t_data_img *texture_img)
{
	if (texture_img)
	{
		if (texture_img->img_ptr)
			mlx_destroy_image(mlx_ptr, texture_img->img_ptr);
		free(texture_img);
	}
}

void	exit_error(char *str, t_map *map)
{
	ft_printf("%s\n", str);
	free_map(&map);
	exit(EXIT_FAILURE);
}
