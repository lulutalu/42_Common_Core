/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:09:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/17 15:31:42 by lduboulo         ###   ########.fr       */
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
