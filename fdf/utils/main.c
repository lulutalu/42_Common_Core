/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/24 21:48:40 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_txt_map	txt;
	t_file		file;
	t_map		map;
	t_res		res;
	t_mlx		mlx;

	file.name = argv[1];
	file.argc = argc;
	///////////////////////
	arg_check(file);
	file_desc_opening(&file);
	////////////////////////
	txt.line = ft_calloc(1, sizeof(char));
	mem_alloc_check(txt.line);
	nl_counter(&txt, file);
	/////////////////////////
	txt.array = ft_calloc((txt.nbline + 1), sizeof(char *));
	mem_alloc_check(txt.array);
	file_desc_closing(&file);
	file_desc_opening(&file);
	array_filling(&txt, file);	
	//////////////////////////
	file_digit_check(&txt);
	//////////////////////////
	int_array(&map, &txt);
	res.x = 1920;
	res.y = 1080;
	//window_init(&mlx, res);
	//To stop loop use txt.nbline - 1 with map.y and map.nb for map.x
	res.x_scale = 100; //res.x / map.nb;
	res.y_scale = 7; //(res.y + 100) / (txt.nbline - 1);
	res.z_scale = 10;
	res.x0 = res.x / 2;
	window_init(&mlx, res);
	drawing_process(&mlx, txt, map, res);
	/*y_axis_algorithm(mlx, txt, &map, res);
	x_axis_algorithm(mlx, txt, &map, res);	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);*/
	mlx_loop(mlx.mlx);
	return (1);
}
