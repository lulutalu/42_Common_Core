/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/26 15:57:23 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->res.x = 1920;
	fdf->res.y = 1080;
	fdf->res.x_scale = 100;
	fdf->res.y_scale = 100;
	fdf->res.z_scale = 15;
	fdf->res.x0 = fdf->res.x / 2;
	fdf->res.y0 = 200;
	fdf->res.alpha = ISO;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (keycode == UP)
			fdf->res.y0 -= 10;
		if (keycode == DOWN)
			fdf->res.y0 += 10;
		if (keycode == LEFT)
			fdf->res.x0 -= 10;
		if (keycode == RIGHT)
			fdf->res.x0 += 10;
		if (keycode == END)
			fdf->res.alpha = ISO;
		if (keycode == HOME)
			fdf->res.alpha = CAV;
		key_hook_2(keycode, fdf);
		drawing_process(fdf);
	}
	return (0);
}

void	key_hook_2(int keycode, t_fdf *fdf)
{
	if (keycode == PGUP)
		fdf->res.z_scale += 2;
	if (keycode == PGDWN)
		fdf->res.z_scale -= 2;
	if (keycode == PLUS)
	{
		fdf->res.x_scale *= 1.1;
		fdf->res.y_scale *= 1.1;
	}
	if (keycode == MINUS)
	{
		fdf->res.x_scale *= 0.9;
		fdf->res.y_scale *= 0.9;
	}
}

int	main(int argc, char **argv)
{
	t_file		file;
	t_fdf		fdf;

	file.name = argv[1];
	file.argc = argc;
	arg_check(file);
	file_desc_opening(&file);
	nl_counter(&fdf, file);
	fdf.txt.array = ft_calloc((fdf.txt.nbline + 1), sizeof(char *));
	mem_alloc_check(fdf.txt.array);
	file_desc_closing(&file);
	file_desc_opening(&file);
	array_filling(&fdf, file);
	file_digit_check(&fdf);
	int_array(&fdf);
	fdf_init(&fdf);
	window_init(&fdf);
	scaling_adjustment(&fdf);
	drawing_process(&fdf);
	mlx_key_hook(fdf.mlx_win, key_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (1);
}
