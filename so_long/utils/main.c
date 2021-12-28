/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:58:22 by lduboulo          #+#    #+#             */
/*   Updated: 2021/12/28 17:54:46 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_square(t_data data, int color)
{
	int	x;
	int y;

	x = 50;
	y = 50;
	while (x <= 450)
		my_mlx_pixel_put(&data, x++, y, color);
	while (y <= 450)
		my_mlx_pixel_put(&data, x, y++, color);
	while (x >= 50)
		my_mlx_pixel_put(&data, x--, y, color);
	while (y >= 50)
		my_mlx_pixel_put(&data, x, y--, color);
}

void	print_line(t_data data, int color)
{

}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "so_long");
	if (mlx_win == NULL)
		return (0);
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_line(img, 0x0000BFFF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

