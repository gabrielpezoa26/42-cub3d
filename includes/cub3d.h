/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteruya <dteruya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:52 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/23 18:45:06 by dteruya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

/*---------MACROS---------*/
# define INVALID_ARGC "Invalid arg count\n"
# define FORMAT "Invalid format. Correct format:\n./cub3D file.cub\n"
# define STRUCT "Invalid struct!!\n"

typedef struct s_info
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_info;

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

typedef struct s_map
{
	int		rows_amount;
	int		cols_amount;
	int		**matrix;
}	t_map;

/*---------PARSER---------*/
bool	parse_input(int ac, char **av, t_info **info, t_map **map);
bool	is_valid_char(int c);
bool	is_valid_extension(const char *filename);
bool	is_valid_file(char *av, t_info **info);
bool	parse_textures(t_map *map, int fd);
bool	parse_map(t_map *map);

bool	map_before(char *file_name);
void	print_and_exit(char *str);

/*---------UTILS---------*/
bool	is_wspace(char input);
bool	is_only_wspace(char *line);

/*---------INIT---------*/
void	init_info(char *file_name, t_info **info);

/*---------CLEANUP---------*/
void	free_array(void **tab, size_t len);
void	free_info(t_info *info);
void	free_map(t_map *map);

/*---------ROSE--------------*/
void	init_south(t_info *info, int *i, char *line);
void	init_east(t_info *info, int *i, char *line);
void	init_west(t_info *info, int *i, char *line);
void	init_north(t_info *info, int *i, char *line);

/*---------------RGB-----------*/
bool	init_rgb(t_info *info, char *line);

/*---------MAP-----------*/
bool	is_valid_map(char *file_name, t_map **map);
void	init_matrix(char *file_name, t_map *map);
void	fill_the_matrix(char *file_name, t_map *map);

#endif