/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/18 16:41:05 by lduboulo         ###   ########.fr       */
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
	res.x_scale = 40; //res.x / map.nb;
	res.y_scale = 40; //(res.y + 100) / (txt.nbline - 1);
	start.x = res.x / 2;
	start.y = 300;
	while (map.y < (txt.nbline - 1))
	{
		final.x = start.x + fabs((map.nb - 1) * res.x_scale * cos(60));
		final.y = start.y + fabs((map.nb - 1) * res.y_scale * sin(60));
		print_line(mlx, start, final);
		map.y++;
		start.x = (res.x / 2) - fabs(map.y * (res.x_scale * cos(60)));
		start.y = 300 + fabs(map.y * (res.y_scale * sin(60)));
	}
	start.x = res.x / 2;
	start.y = 300;
	map.x = 0;
	while (map.x < map.nb)
	{
		final.x = start.x - fabs((txt.nbline - 2) * res.x_scale * cos(60));
		final.y = start.y + fabs((txt.nbline - 2) * res.y_scale * sin(60));
		print_line(mlx, start, final);
		map.x++;
		start.x = (res.x / 2) + fabs(map.x * (res.x_scale * cos(60)));
		start.y = 300 + fabs(map.x * (res.y_scale * sin(60)));
	}
	/*x_proj = sqrt(3) * (1 / sqrt(6));
	y_proj = (1 / sqrt(6));
	printf("Projection X : %f\nProjection Y : %f\n", x_proj, y_proj);
	while (map.y < (txt.nbline - 1))
	{
		start.y = ((map.y * res.y_scale) + (res.y_scale / 2)) * y_proj;
		final.y = start.y;
		map.x = 0;
		while (map.x < (map.nb - 1))
		{
			start.x = ((map.x * res.x_scale) + (res.x_scale / 2)) * x_proj;
			map.x++;
			final.x = ((map.x * res.x_scale) + (res.x_scale / 2)) * x_proj;
			print_line(mlx, start, final);
		}
		map.y++;
	}
	map.x = 0;
	while (map.x < map.nb)
	{
		start.x = ((map.x * res.x_scale) + (res.x_scale / 2)) * x_proj;
		final.x = start.x;
		map.y = 0;
		while (map.y < (txt.nbline - 2))
		{
			start.y = ((map.y * res.y_scale) + (res.y_scale / 2)) * y_proj;
			map.y++;
			final.y = ((map.y * res.y_scale) + (res.y_scale / 2)) * y_proj;
			print_line(mlx, start, final);
		}
		map.x++;
	}*/
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (1);
}
