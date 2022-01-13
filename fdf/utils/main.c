/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/13 22:37:07 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_txt_map	txt;
	t_file		file;
	t_map		map;
	//t_coord		start;
	//t_coord		final;
	//t_mlx		mlx;
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
	//window_init(&mlx, res);
	//At this point of the process, map.x is equal to the number of line
	//And map.y is bigger by 1 to the number of "words" and equal to map.nb
	//With those information, we can decide to use map.nb to set up frontier
	map.x = 0;
	map.y = 0;
	printf("Nombre de lignes : %d Nombre de points %d\n", txt.nbline, map.nb);
	while (map.y < (txt.nbline - 1))
	{
		map.x = 0;
		while (map.x < map.nb)
			printf("%d ", map.map[map.y][map.x++]);
		printf("\n");
		map.y++;
	}
	/*res.x_scale = res.x / map.nb;
	res.y_scale = res.y / map.nb;	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);*/
	return (1);
}
