/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_scaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:56:43 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/25 15:39:43 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling_adjustment(t_txt_map txt, t_map map, t_res *res)
{
	float	x_max;
	float	x_min;
	float	y_max;

	x_max = 500;
	x_min = 500;
	while ((x_max > (res->x - 50) || x_max < (res->x - 150)) \
			|| (x_min > 250 || x_min < 100))
	{
		scaling_adjustment_x_max(map, res);
		scaling_adjustment_x0(txt, res);
		printf("x scale %f\n", res->x_scale);
		x_max = res->x0 + map.nb * fabs(res->x_scale * cos(ALPHA));
		x_min = res->x0 - (txt.nbline - 1) * fabs(res->x_scale * cos(ALPHA));
	}
	y_max = 100;
	while (y_max < (res->y - 125) || y_max > (res->y - 75))
	{
		scaling_adjustment_y_max(map, txt, res);
		y_max = 100 + (map.nb + txt.nbline) * fabs(res->y_scale * sin(ALPHA));
		printf("Y_max : %f\n", y_max);
	}
}

void	scaling_adjustment_y_max(t_map map, t_txt_map txt, t_res *res)
{
	float	y_max;

	y_max = 100 + (map.nb + txt.nbline) * fabs(res->y_scale * sin(ALPHA));
	if (y_max < (res->y - 100))
		res->y_scale *= 1.1;
	if (y_max > (res->y - 100))
		res->y_scale *= 0.9;
}

void	scaling_adjustment_x_max(t_map map, t_res *res)
{
	float	x_max;

	x_max = res->x0 + map.nb * fabs(res->x_scale * cos(ALPHA));
	if (x_max < (res->x - 100))
		res->x_scale *= 1.1;
	if (x_max > (res->x - 100))
		res->x_scale *= 0.9;
}

void	scaling_adjustment_x0(t_txt_map txt, t_res *res)
{
	float	x_min;

	x_min = res->x0 - (txt.nbline - 1) * fabs(res->x_scale * cos(ALPHA));
	if (x_min > 175)
		res->x0 *= 0.9;
	if (x_min < 175)
		res->x0 *= 1.1;
}
