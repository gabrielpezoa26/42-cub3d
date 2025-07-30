/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:14:23 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/28 19:48:27 by gcesar-n         ###   ########.fr       */
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
