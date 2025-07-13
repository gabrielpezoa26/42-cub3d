/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:22:52 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/07/13 01:17:11 by gcesar-n         ###   ########.fr       */
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
# define MAP "Invalid map!!\n"

typedef struct s_map
{
	int		rows_amount;
	int		cols_amount;
}	t_map;

/*---------PARSER---------*/
bool	parse_input(int argc, char **argv);
bool	is_valid_char(int c);
bool	is_valid_extension(const char *filename);
bool	parse_file(char **av);

#endif