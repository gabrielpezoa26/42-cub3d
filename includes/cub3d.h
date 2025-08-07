/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:28:04 by dteruya           #+#    #+#             */
/*   Updated: 2025/08/07 13:06:40 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

/*---------MACROS---------*/
# define FORMAT "Invalid format. Correct format:\n./cub3D file.cub\n"
# define STRUCT "Invalid struct!!\n"
# define MLX "Error initializing mlx\n"
# define INVALID_ARGC "Invalid arg count\n"

# define WALL_VALUE 1
# define EMPTY_VALUE 0
# define VISITED_VALUE 9

# define WIDTH 800
# define HEIGHT 800
# define TITLE "CUB 3D"
# define MOVE_SPEED 0.02
# define ROT_SPEED 0.02

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_data_img
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data_img;

typedef struct s_info
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_info;

typedef struct s_texture
{
	t_data_img	*north;
	t_data_img	*south;
	t_data_img	*west;
	t_data_img	*east;
}	t_texture;

typedef struct s_ray
{
	double	cam_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_dist;
	int		y_pixel;
	int		start;
	int		end;
	int		line_height;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_player
{
	double	position_x;
	double	position_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	bool	is_moving_forward;
	bool	is_moving_backward;
	bool	is_moving_left;
	bool	is_moving_right;
	bool	is_rotating_left;
	bool	is_rotating_right;
}	t_player;

typedef struct s_map
{
	int			rows_amount;
	int			cols_amount;
	int			**matrix;
	void		*mlx_ptr;
	void		*window_ptr;
	char		letter;
	t_ray		ray;
	t_data_img	*img;
	t_point		*pov;
	t_info		*info;
	t_texture	*text;
	t_player	*player;
}	t_map;

/*---------PARSER---------*/
bool	parse_input(int ac, char **av, t_info **info, t_map **map);
bool	is_valid_char(int c);
bool	is_valid_extension(const char *filename);
bool	is_valid_file(char *av, t_info **info);
bool	is_map_before(char *file_name);
void	print_and_exit(char *str);

/*---------UTILS---------*/
bool	is_wspace(char input);
bool	is_only_wspace(char *line);
void	init_texture_struct(t_map *map);
void	init_data_img(t_map *map);
void	init_player(t_map *map);
void	convert_rgb_colors(t_map *map);

/*---------INIT---------*/
void	init_info(char *file_name, t_info **info);
void	init_south(t_info *info, int *i, char *line);
void	init_east(t_info *info, int *i, char *line);
void	init_west(t_info *info, int *i, char *line);
void	init_north(t_info *info, int *i, char *line);

/*---------CLEANUP---------*/
void	free_map(t_map **map);
void	free_matrix(int **matrix, int height);
void	exit_error(char *str, t_map *map);
void	free_single_texture(void *mlx_ptr, t_data_img *texture_img);
int		close_game(t_map *map);

/*---------------RGB-----------*/
int		rgb_to_int(int r, int g, int b);
bool	init_rgb(t_info *info, char *line);

/*---------MAP-----------*/
bool	is_valid_map(char *file_name, t_map **map, t_info **info);
void	init_matrix(char *file_name, t_map *map);
void	fill_the_matrix(char *file_name, t_map *map);

/*---------FLOOD_FILL--------*/
bool	flood_fill_recursive(t_map **map, int **map_copy, int x, int y);
bool	flood_fill_validation(t_map **map);
int		**dup_int_matrix(t_map *map);

/*--------------------EXEC------------------*/
void	execution(t_map *map);

/*--------------------EXEC_UTILS------------------*/
void	set_north_values(t_map *map);
void	set_south_values(t_map *map);
void	set_east_values(t_map *map);
void	set_west_values(t_map *map);

/*--------------LOAD_TEXT--------------------*/
void	init_textures(t_map *map);
void	load_north_texture(t_map *map);
void	load_south_texture(t_map *map);
void	load_east_texture(t_map *map);
void	load_west_texture(t_map *map);
int		get_texture_color(t_data_img *texture, int x, int y);

/*---------RENDER---------------*/
int		render(void *param);
void	draw_textured_wall(t_map *map, int x);
void	draw_ceiling_and_floor(t_map *map, int x);
void	loop_dda(t_ray *ray, t_map *map);
void	dda(t_ray *ray, t_player *player);
void	my_mlx_pixel_put(t_data_img *img, int x, int y, int color);

/*---------GRAPHICS---------------*/
void	init_graphics(t_map *map);

/*---------CONTROLS---------------*/
void	rotate_left(t_player *player);
void	rotate_right(t_player *player);
int		key_press_hook(int keycode, t_map *map);
int		key_release_hook(int keycode, t_map *map);
void	update_player_position(t_map *map);

#endif