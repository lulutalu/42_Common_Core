/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:58:22 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/05 22:17:53 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

void	print_square(t_mlx win, int color)
{
	int	x;
	int y;

	x = 50;
	y = 50;
	while (x <= 450)
		mlx_pixel_put(win.mlx, win.mlx_win, x++, y, color);
	while (y <= 450)
		mlx_pixel_put(win.mlx, win.mlx_win, x, y++, color);
	while (x >= 50)
		mlx_pixel_put(win.mlx, win.mlx_win, x--, y, color);
	while (y >= 50)
		mlx_pixel_put(win.mlx, win.mlx_win, x, y--, color);
}

void	print_line(t_mlx win, int color, int Xstart, int Ystart, int Xfinal, int Yfinal)
{
	double	Xprint;
	double	Yprint;
	double	Xdelta;
	double	Ydelta;
	int		len;

	Xprint = Xstart;
	Yprint = Ystart;
	Xdelta = Xfinal - Xstart;
	Ydelta = Yfinal - Ystart;
	len = sqrt((Xdelta * Xdelta) + (Ydelta * Ydelta));
	Xdelta /= len;
	Ydelta /= len;
	while (len > 0)
	{
		mlx_pixel_put(win.mlx, win.mlx_win, Xprint, Yprint, color);
		Xprint += Xdelta;
		Yprint += Ydelta;
		len--;
	}
}

void	print_triangle(t_mlx win, int color, int Ax, int Ay, int Bx, int By, int Cx, int Cy)
{
	print_line(win, color, Ax, Ay, Bx, By);
	print_line(win, color, Bx, By, Cx, Cy);
	print_line(win, color, Cx, Cy, Ax, Ay);
}

int	main(void)
{
	//t_data	img;
	t_mlx	win;
	int		i;

	i = 0;
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, 500, 500, "so_long");
	if (win.mlx_win == NULL)
		return (0);
	/*img.img = mlx_new_image(win.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);*/
	//print_square(win, 0x0000BFFF);
//	print_line(win, 0x0000BFFF, 50, 50, 50, 200);
	print_triangle(win, 0x00EE82EE, 20, 300, 300, 300, 150, 40);
	//mlx_put_image_to_window(win.mlx, win.mlx_win, img.img, 0, 0);
	mlx_loop(win.mlx);
}
