/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_scaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:56:43 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/24 20:38:40 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling_adjustment(t_txt_map txt, t_map map, t_res *res)
{
	float	x_max;
	float	x_min;

	x_max = 500;
	x_min = 500;
	while ((x_max > (res->x - 100) || x_max < (res->x - 300)) \
			|| (x_min > 250 || x_min < 150))
	{
		printf("Before Scaling en x : %f\n", res->x_scale);
		scaling_adjustment_x_max(map, res);
		scaling_adjustment_x0(txt, res);
		x_max = res->x0 + map.nb * fabs(res->x_scale * cos(ALPHA));
		printf("x max : %f\n", x_max);
		x_min = res->x0 - (txt.nbline - 1) * fabs(res->x_scale * cos(ALPHA));
		printf("x min : %f\n", x_min);
		printf("After Scaling en x : %f\n", res->x_scale);
	}
}

void	scaling_adjustment_x_max(t_map map, t_res *res)
{
	float	x_max;

	x_max = res->x0 + map.nb * fabs(res->x_scale * cos(ALPHA));
	while (x_max < (res->x - 300) || x_max > (res->x - 100))
	{
		x_max = res->x0 + map.nb * fabs(res->x_scale * cos(ALPHA));
		if (x_max < (res->x - 100))
			res->x_scale *= 1.1;
		if (x_max > (res->x - 100))
			res->x_scale *= 0.9;
	}
}

void	scaling_adjustment_x0(t_txt_map txt, t_res *res)
{
	float	x_min;

	x_min = res->x0 - (txt.nbline - 1) * fabs(res->x_scale * cos(ALPHA));
	while (x_min > 250 || x_min < 150)
	{
		x_min = res->x0 - (txt.nbline - 1) * fabs(res->x_scale * cos(ALPHA));
		if (x_min > 200)
			res->x0 *= 0.9;
		if (x_min < 200)
			res->x0 *= 1.1;
	}
}
