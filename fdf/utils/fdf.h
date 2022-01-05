/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:43:09 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/05 15:12:57 by lduboulo         ###   ########.fr       */
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

/*
 * Structures
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
	int		x;
	int		y;
}				t_map;

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

#endif
