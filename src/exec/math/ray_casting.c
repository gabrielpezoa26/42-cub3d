/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:31:47 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/30 18:40:08 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void my_mlx_pixel_put(t_data_img *img, int x, int y, int color)
{
	char *dst;

	// Basic bounds checking to prevent writing outside the image buffer
	// You should define WIDTH and HEIGHT, probably in a header file.
	// Assuming WIDTH and HEIGHT are the dimensions of your window.
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) // Make sure WIDTH and HEIGHT are defined
		return;

	// Calculate the memory address of the pixel
	// img->addr is the starting address of the pixel data for the image
	// y * img->line_length moves to the correct row (line_length is bytes per line)
	// x * (img->bits_per_pixel / 8) moves to the correct column (bytes per pixel)
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	// Cast the address to an unsigned int pointer and assign the color
	// This assumes 32 bits per pixel (4 bytes), common for RGB.
	*(unsigned int*)dst = color;
}

// 1. Calcular a direção do raio (rayDirX, rayDirY)
static void	direction(t_player *player, t_ray *ray, int index)
{
	ray->cam_x = 2 * index / (double)WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->cam_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->cam_x;
}

// 2. Inicializar o DDA (mapX, mapY, sideDistX, sideDistY, deltaDistX, deltaDistY)
static void	dda(t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->position_x;
	ray->map_y = (int)player->position_y;
	if (ray->ray_dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->position_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - player->position_x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->position_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->position_y) * ray->delta_y;
	}
}

// 3. Loop do DDA (encontrar a parede)
void	loop_dda(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->matrix[ray->map_y][ray->map_x] == 1)
			ray->hit = 1;
	}
}

// 4. Calcular a distância perpendicular (perpWallDist)
void	calculate_distance(t_ray *ray, t_player *player)
{
	double	map;
	double	pos;
	double	step;
	double	dir;

	if (ray->side == 0)
	{
		map = (double)ray->map_x;
		pos = player->position_x;
		step = (double)ray->step_x;
		dir = ray->ray_dir_x;
		ray->wall_dist = (map - pos + (1.0 - step) / 2.0) / dir;
	}
	else
	{
		map = (double)ray->map_y;
		pos = player->position_y;
		step = (double)ray->step_y;
		dir = ray->ray_dir_y;
		ray->wall_dist = (map - pos + (1.0 - step) / 2.0) / dir;
	}
}

// 5. Calcular a altura da parede na tela (lineHeight, drawStart, drawEnd)
void	calculate_wall(t_ray *ray)
{
	if (ray->wall_dist == 0)
		ray->wall_dist= 0.001;
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->start = ray->line_height / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT -1;
}

void	draw_ceiling(t_map *map, t_ray *ray, int x)
{
	ray->y_pixel = 0;
	while (ray->y_pixel < map->ray.start)
	{
		my_mlx_pixel_put(map->img, x, ray->y_pixel, 0x0087CEEB);
		ray->y_pixel++;
	}
}

void	draw_wall(t_ray *ray, t_map *map, int x)
{
	int color;

	while (ray->y_pixel < map->ray.end)
	{
		if (map->ray.side == 0)
			color = 0x00FF0000;
		else
			color = 0x0000FF00;

		my_mlx_pixel_put(map->img, x, ray->y_pixel, color);
		ray->y_pixel++;
	}
}

void	draw_floor(t_ray *ray, t_map *map, int x)
{
	while (ray->y_pixel < HEIGHT)
	{
		my_mlx_pixel_put(map->img, x, ray->y_pixel, 0x008B4513);
		ray->y_pixel++;
	}
}

int	render(void *param)
{
	t_map	*map;
	int		x;

	map = (t_map *)param;
	x = 0;
	while (x < WIDTH)
	{
		// --- CÓDIGO DO RAYCASTING PARA A COLUNA 'x' ---
		// 1. Calcular a direção do raio (rayDirX, rayDirY)
		direction(map->player, &map->ray, x);
		printf("1\n\n");
		// 2. Inicializar o DDA (mapX, mapY, sideDistX, sideDistY, deltaDistX, deltaDistY)
		dda(&map->ray, map->player);
		printf("2\n\n");

		// 3. Loop do DDA (encontrar a parede)
		loop_dda(&map->ray, map);
		printf("3\n\n");

		// 4. Calcular a distância perpendicular (perpWallDist)
		calculate_distance(&map->ray, map->player);
		printf("4\n\n");

		// 5. Calcular a altura da parede na tela (lineHeight, drawStart, drawEnd)
		calculate_wall(&map->ray);
		printf("5\n\n");

		// 6. Desenhar o TETO para a coluna 'x'
		draw_ceiling(map, &map->ray, x);
		printf("6\n\n");

		// 7. Desenhar a PAREDE para a coluna 'x' (aplicando textura depois)
		draw_wall(&map->ray, map, x);
		printf("7\n\n");

		// 8. Desenhar o CHÃO para a coluna 'x'
		draw_floor(&map->ray, map, x);
		printf("8\n\n");
		x++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->window_ptr, map->img->img_ptr, 0, 0);
	printf("DEBUG: frame rendered\n");
	return (0);
}
