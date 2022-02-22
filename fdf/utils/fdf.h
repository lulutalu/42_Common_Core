/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:43:09 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/22 18:26:41 by lduboulo         ###   ########.fr       */
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
# define ESC 53

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
	double			x;
	double			y;
	int				z;
	int				color;
	struct s_coord	*start;
	struct s_coord	*final;
}				t_coord;

typedef struct s_line {
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	int		len;
}				t_line;

typedef struct s_res {
	float	x;
	float	y;
	float	x0;
	float	y0;
	float	x_scale;
	float	y_scale;
	float	z_scale;
}				t_res;

typedef struct s_fdf {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	t_txt_map	txt;
	t_map		map;
	t_res		res;
}				t_fdf;

/*
 * File checking
*/

int		extension_checker(char *filename);
void	arg_check(t_file file);
void	file_digit_check(t_fdf *fdf);

/*
 * File Descriptor Manipulation
*/

void	file_desc_opening(t_file *file);
void	file_desc_closing(t_file *file);

/*
 * Map Manipulation and storage inside array
*/

void	nl_counter(t_fdf *fdf, t_file file);
void	array_filling(t_fdf *fdf, t_file file);
void	int_array(t_fdf *fdf);

/*
 * Little Functions
*/

int		color_selection(t_coord coord);
void	mem_alloc_check(void *ptr);

/*
 * Scaling Functions
*/

void	scaling_adjustment_y_min(t_fdf *fdf);
void	scaling_adjustment_y_max(t_fdf *fdf);
void	scaling_adjustment_x_max(t_fdf *fdf);
void	scaling_adjustment_x0(t_fdf *fdf);
void	scaling_adjustment(t_fdf *fdf);

/*
 * mlx functions
*/

void	drawing_process(t_fdf *fdf);
void	y_axis_draw(t_coord *coord, t_fdf *fdf);
void	y_axis_algorithm(t_fdf *fdf);
void	x_axis_draw(t_coord *coord, t_fdf *fdf);
void	x_axis_algorithm(t_fdf *fdf);
void	window_init(t_fdf *fdf);
void	print_line(t_coord coord, t_fdf fdf, int color);
void	my_mlx_pixel_put(t_fdf *fdf, t_line *line, int color);

/*
 * Mlx Hooks
*/

int	key_hook(int keycode, t_fdf *fdf);
//int	res_hook(int keycode, t_res *res);

#endif
