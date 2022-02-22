/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/22 18:26:43 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 126)
	{
		printf("Print");
	}
	return (0);
}

/*int	res_hook(int keycode, t_res *res)
{
	if (keycode == 126)
		printf("Hello %f\n", res->y_scale);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_file		file;
	t_fdf		fdf;

	file.name = argv[1];
	file.argc = argc;
	///////////////////////
	arg_check(file);
	file_desc_opening(&file);
	////////////////////////
	fdf.txt.line = ft_calloc(1, sizeof(char));
	mem_alloc_check(fdf.txt.line);
	nl_counter(&fdf, file);
	/////////////////////////
	fdf.txt.array = ft_calloc((fdf.txt.nbline + 1), sizeof(char *));
	mem_alloc_check(fdf.txt.array);
	file_desc_closing(&file);
	file_desc_opening(&file);
	array_filling(&fdf, file);	
	//////////////////////////
	file_digit_check(&fdf);
	//////////////////////////
	int_array(&fdf);
	fdf.res.x = 1920;
	fdf.res.y = 1080;
	//To stop loop use txt.nbline - 1 with map.y and map.nb for map.x
	fdf.res.x_scale = 100; //res.x / map.nb;
	fdf.res.y_scale = 100; //(res.y + 100) / (txt.nbline - 1);
	fdf.res.z_scale = 15;
	fdf.res.x0 = fdf.res.x / 2;
	fdf.res.y0 = 200;
	window_init(&fdf);
	drawing_process(&fdf);
	mlx_key_hook(fdf.mlx_win, key_hook, &fdf);
//	mlx_key_hook(mlx.mlx_win, res_hook, &res);
	mlx_loop(fdf.mlx);
	return (1);
}
