/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:09:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/22 18:26:42 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, fdf->res.x, fdf->res.y, "fdf");
	if (fdf->mlx_win == NULL)
	{
		ft_putendl_fd(WIN_ERROR, 2);
		exit(EXIT_FAILURE);
	}
	fdf->img = mlx_new_image(fdf->mlx, fdf->res.x, fdf->res.y);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
			&fdf->line_length, &fdf->endian);
}

void	my_mlx_pixel_put(t_fdf *fdf, t_line *line, int color)
{
	char	*dst;

	dst = fdf->addr + ((int)line->y * fdf->line_length + \
			(int)line->x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawing_process(t_fdf *fdf)
{
	scaling_adjustment(fdf);
	y_axis_algorithm(fdf);
	x_axis_algorithm(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}
