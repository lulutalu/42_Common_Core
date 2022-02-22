/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drawing_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/22 19:09:31 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_coord coord, t_fdf fdf, int color)
{
	t_line	line;

	line.x = coord.start->x;
	line.y = coord.start->y;
	line.delta_x = coord.final->x - coord.start->x;
	line.delta_y = coord.final->y - coord.start->y;
	line.len = sqrt((line.delta_x * line.delta_x) \
			+ (line.delta_y * line.delta_y));
	line.delta_x /= line.len;
	line.delta_y /= line.len;
	while (line.len > 0)
	{
		if ((line.x <= fdf.res.x && line.x >= 0) && \
				(line.y <= fdf.res.y && line.y >= 0))
			my_mlx_pixel_put(&fdf, &line, color);
		line.x += line.delta_x;
		line.y += line.delta_y;
		line.len--;
	}
}

void	y_axis_algorithm(t_fdf *fdf)
{
	t_coord	coord;

	coord.start = malloc(sizeof(coord));
	coord.final = malloc(sizeof(coord));
	fdf->map.y = 0;
	while (fdf->map.y < (fdf->txt.nbline - 1))
	{
		fdf->map.x = 0;
		while (fdf->map.x < (fdf->map.nb - 1))
		{
			coord.start->x = fdf->res.x0 + ((fdf->map.y * -1 + fdf->map.x) * \
					fabs(fdf->res.x_scale * cos(fdf->res.alpha)));
			coord.start->y = fdf->res.y0 + ((fdf->map.y + fdf->map.x) * \
					fabs(fdf->res.y_scale * sin(fdf->res.alpha)));
			coord.start->z = fdf->map.map[fdf->map.y][fdf->map.x++];
			coord.final->z = fdf->map.map[fdf->map.y][fdf->map.x];
			y_axis_draw(&coord, fdf);
			print_line(coord, *fdf, color_selection(coord));
		}	
		fdf->map.y++;
	}
	free(coord.start);
	free(coord.final);
}

void	y_axis_draw(t_coord *coord, t_fdf *fdf)
{
	if (coord->start->z == 0 && coord->final->z == 0)
	{
		coord->final->x = coord->start->x + fabs(fdf->res.x_scale * cos(fdf->res.alpha));
		coord->final->y = coord->start->y + fabs(fdf->res.y_scale * sin(fdf->res.alpha));
	}
	else if (coord->start->z == coord->final->z)
	{
		coord->final->x = coord->start->x + fabs(fdf->res.x_scale * cos(fdf->res.alpha));
		coord->start->y -= fdf->res.z_scale * coord->start->z;
		coord->final->y = coord->start->y + fabs(fdf->res.y_scale * sin(fdf->res.alpha));
	}
	else if (coord->start->z != coord->final->z)
	{
		coord->final->x = coord->start->x + fabs(fdf->res.x_scale * cos(fdf->res.alpha));
		coord->final->y = coord->start->y + fabs(fdf->res.y_scale * sin(fdf->res.alpha)) \
					- (fdf->res.z_scale * coord->final->z);
		coord->start->y -= fdf->res.z_scale * coord->start->z;
	}
}

void	x_axis_algorithm(t_fdf *fdf)
{
	t_coord	coord;

	coord.start = malloc(sizeof(coord));
	coord.final = malloc(sizeof(coord));
	fdf->map.x = 0;
	while (fdf->map.x < fdf->map.nb)
	{
		fdf->map.y = 0;
		while (fdf->map.y < (fdf->txt.nbline - 2))
		{
			coord.start->x = fdf->res.x0 + ((fdf->map.y * -1 + fdf->map.x) \
					* fabs(fdf->res.x_scale * cos(fdf->res.alpha)));
			coord.start->y = fdf->res.y0 + ((fdf->map.y + fdf->map.x) * \
					fabs(fdf->res.y_scale * sin(fdf->res.alpha)));
			coord.start->z = fdf->map.map[fdf->map.y++][fdf->map.x];
			coord.final->z = fdf->map.map[fdf->map.y][fdf->map.x];
			x_axis_draw(&coord, fdf);
			print_line(coord, *fdf, color_selection(coord));
		}
		fdf->map.x++;
	}
	free(coord.start);
	free(coord.final);
}

void	x_axis_draw(t_coord *coord, t_fdf *fdf)
{
	if (coord->start->z == 0 && coord->final->z == 0)
	{
		coord->final->x = coord->start->x - fabs(fdf->res.x_scale * cos(fdf->res.alpha));
		coord->final->y = coord->start->y + fabs(fdf->res.y_scale * sin(fdf->res.alpha));
	}
	else if (coord->start->z == coord->final->z)
	{
		coord->final->x = coord->start->x - fabs(fdf->res.x_scale * cos(fdf->res.alpha));
		coord->start->y -= fdf->res.z_scale * coord->start->z;
		coord->final->y = coord->start->y + fabs(fdf->res.y_scale * sin(fdf->res.alpha));
	}
	else if (coord->start->z != coord->final->z)
	{
		coord->final->x = coord->start->x - fabs(fdf->res.x_scale * cos(fdf->res.alpha));
		coord->final->y = coord->start->y + fabs(fdf->res.y_scale * sin(fdf->res.alpha)) \
					- (fdf->res.z_scale * coord->final->z);
		coord->start->y -= fdf->res.z_scale * coord->start->z;
	}
}
