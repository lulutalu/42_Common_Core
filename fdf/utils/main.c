/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/14 15:50:58 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_txt_map	txt;
	t_file		file;
	t_map		map;
	t_coord		start;
	t_coord		final;
	t_mlx		mlx;
	t_res		res;

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
	window_init(&mlx, res);
	//To stop loop use txt.nbline - 1 with map.y and map.nb for map.x
	map.y = 0;
	map.x = 0;
	res.x_scale = res.x / (map.nb - 1);
	res.y_scale = res.y / (txt.nbline - 2);
	if (map.y == 0 && map.x == 0)
	{
		start.y = map.y * res.y_scale;
		start.x = map.x * res.x_scale;
		final.y = (map.y + 1) * res.y_scale;
		final.x = start.x;
		print_line(mlx, start, final);
		final.y = start.y;
		final.x = (map.x + 1) * res.x_scale;
		print_line(mlx, start, final);
	}
	map.x = (map.nb - 1);
	if (map.y == 0 && map.x == (map.nb - 1))
	{
		start.y = map.y * res.y_scale;
		start.x = map.x * res.x_scale;
		final.y = (map.y + 1) * res.y_scale;
		final.x = start.x;
		print_line(mlx, start, final);
		final.y = start.y;
		final.x = (map.x - 1) * res.x_scale;
		print_line(mlx, start, final);
	}
	map.y = (txt.nbline - 2);
	map.x = 0;
	if (map.y == (txt.nbline - 2) && map.x == 0)
	{
		start.y = (map.y * res.y_scale) - 1;
		start.x = map.x * res.x_scale;
		final.y = (map.y - 1) * res.y_scale;
		final.x = start.x;
		print_line(mlx, start, final);
		final.y = start.y;
		final.x = (map.x + 1) * res.x_scale;
		print_line(mlx, start, final);
	}
	map.x = (map.nb - 1);
	if (map.y == (txt.nbline - 2) && map.x == (map.nb - 1))
	{
		start.y = (map.y * res.y_scale) - 1;
		start.x = (map.x * res.x_scale) - 1;
		final.y = (map.y - 1) * res.y_scale;
		final.x = start.x;
		print_line(mlx, start, final);
		final.y = start.y;
		final.x = (map.x - 1) * res.x_scale;
		print_line(mlx, start, final);
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (1);
}
