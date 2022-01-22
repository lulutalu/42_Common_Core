/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:43:09 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/22 19:28:51 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf.h"
# include "./../libft/libft.h"
# include "./get_next_line.h"
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <math.h>

/*
 * Macro
*/

# define ARG_NUMBER "\033[1;31mThe number of arguments is incorrect\033[0m"
# define FILE_EXT "\033[1;31mThe argument possess the wrong extension\033[0m"
# define FD_OP_ERROR "\033[1;31mAn error occured while opening the file\033[0m"
# define FD_CLS_ERROR "\033[1;31mAn error occured while closing the file\033[0m"
# define NOT_DIGIT "\033[1;31mThe file is not entirely filled with number\033[0m"
# define ALLOC_ER "\033[1;31mDynamic Allocation fail\033[0m"
# define WIN_ERROR "\033[1;31mError while creating the window\033[0m"
# define WHITE 0x96FFFFFF  
# define PURPLE 0x00BF40BF
# define RED 0x00C41E3A
# define BLACK 0x00000000
# define BLUE 0x004682B4
# define ALPHA 60

/*
 * Structures for Array
*/

typedef struct s_file {
	int		fd;
	char	*name;
	int		argc;
}				t_file;

typedef struct s_txt_map {
	char	*line;
	int		y;
	int		x;
	int		nbline;
	char	**array;
}				t_txt_map;

typedef struct s_map {
	int		**map;
	char	**splited;
	int		nb;
	int		x;
	int		y;
}				t_map;

/*
 * Structures for mlx and drawing
*/

typedef struct s_coord {
	double	x;
	double	y;
	int		z;
	int		color;
}				t_coord;

typedef struct s_line {
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	int		len;
}				t_line;

typedef struct s_mlx {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_res {
	float	x;
	float	y;
	float	x0;
	float	x_scale;
	float	y_scale;
	float	z_scale;
}				t_res;

/*
 * File checking
*/

int		extension_checker(char *filename);
void	arg_check(t_file file);
void	file_digit_check(t_txt_map *txt);

/*
 * File Descriptor Manipulation
*/

void	file_desc_opening(t_file *file);
void	file_desc_closing(t_file *file);

/*
 * Map Manipulation and storage inside array
*/

void	nl_counter(t_txt_map *txt, t_file file);
void	array_filling(t_txt_map *txt, t_file file);
void	int_array(t_map *map, t_txt_map *txt);

/*
 * Little Functions
*/

int		color_selection(t_coord start, t_coord final);
void	mem_alloc_check(void *ptr);

/*
 * mlx functions
*/

void	scaling_adjustment(t_txt_map txt, t_map map, t_res *res);
void	clear_map(t_res res, t_mlx mlx);
void	drawing_process(t_mlx *mlx, t_txt_map txt, t_map map, t_res res);
void	y_axis_draw(t_coord *start, t_coord *final, t_res res);
void	y_axis_algorithm(t_mlx mlx, t_txt_map txt, t_map *map, t_res *res);
void	x_axis_draw(t_coord *start, t_coord *final, t_res res);
void	x_axis_algorithm(t_mlx mlx, t_txt_map txt, t_map *map, t_res *res);
void	window_init(t_mlx *mlx, t_res res);
void	print_line(t_mlx win, t_coord start, t_coord final, int color);
void	my_mlx_pixel_put(t_mlx *mlx, t_line *line, int color);

#endif
