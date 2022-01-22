/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:09:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/22 19:50:32 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window_init(t_mlx *mlx, t_res res)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, res.x, res.y, "fdf");
	if (mlx->mlx_win == NULL)
	{
		ft_putendl_fd(WIN_ERROR, 2);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->mlx, res.x, res.y);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
			&mlx->line_length, &mlx->endian);
}

void	my_mlx_pixel_put(t_mlx *mlx, t_line *line, int color)
{
	char	*dst;

	dst = mlx->addr + ((int)line->y * mlx->line_length + \
			(int)line->x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawing_process(t_mlx *mlx, t_txt_map txt, t_map map, t_res res)
{
	scaling_adjustment(txt, map, &res);
	y_axis_algorithm(*mlx, txt, &map, &res);
	x_axis_algorithm(*mlx, txt, &map, &res);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

void	scaling_adjustment(t_txt_map txt, t_map map, t_res *res)
{
	float	x_max;
	float	x_min;
	float	y_max;

	x_max = 0;
	while (x_max < (res->x - 100))
	{
		x_max = res->x0 + map.nb * fabs(res->x_scale * cos(ALPHA));
		if (x_max < (res->x - 100))
			res->x_scale *= 1.1;
		if (x_max > res->x)
			res->x_scale *= 0.9;
	}
	x_min = 210;
	while (x_min > 200)
	{
		x_min = res->x0 - (txt.nbline - 1) * fabs(res->x_scale * cos(ALPHA));
		if (x_min > 200)
			res->x0 *= 0.9;
		if (x_min < 200)
			res->x0 *= 1.1;
	}
	y_max = 100 + (txt.nbline - 1 + map.nb) * fabs(res->y_scale * sin(ALPHA));
	printf("Scale : %f\n", res->x_scale);
}

void	clear_map(t_res res, t_mlx mlx)
{
	t_coord	start;
	t_coord	final;

	start.y = 0;
	while (start.y < res.y)
	{
		final.y = start.y;
		start.x = 0;
		while (start.x < res.x)
		{
			final.x = start.x + 1;
			print_line(mlx, start, final, BLACK);
			start.x += 1;
		}
		start.y += 1;
	}
}
