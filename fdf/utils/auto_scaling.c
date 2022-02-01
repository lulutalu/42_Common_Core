/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_scaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:56:43 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/01 14:33:29 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling_adjustment(t_txt_map txt, t_map map, t_res *res)
{
	float	x_max;
	float	x_min;
	float	y_max;
	float	y_min;

	x_max = 500;
	x_min = 500;
	while ((x_max > (res->x - 50) || x_max < (res->x - 150)) \
			|| (x_min > 250 || x_min < 75))
	{
		scaling_adjustment_x_max(map, res);
		scaling_adjustment_x0(txt, res);
		printf("x scale %f\n", res->x_scale);
		x_max = res->x0 + map.nb * fabs(res->x_scale * cos(ALPHA));
		x_min = res->x0 - (txt.nbline - 1) * fabs(res->x_scale * cos(ALPHA));
	}
	y_max = 100;
	while (y_max < (res->y - 200) || y_max > (res->y - 100))
	{
		scaling_adjustment_y_max(map, txt, res);
		y_max = res->y0 + (map.nb + txt.nbline) * fabs(res->y_scale * sin(ALPHA));
		printf("Y scale : %f\n", res->y_scale);
	}
	y_min = 500;
	//if (mean_value_tab(map, txt) != 0)
	//{
		/*find_z_critical(&map, txt, */printf("%f\n", mean_value_tab(map, txt));
		find_max_z_value(&map, txt, mean_value_tab(map, txt));
		while (y_min < 50 || y_min > 150)
		{
			scaling_adjustment_y_min(map, res);
			y_min = res->y0 - map.map[map.y][map.x] * res->z_scale \
					+ (map.x + map.y) * fabs(res->y_scale * sin(ALPHA));
			printf("Z scale : %f y_min : %f\n", res->z_scale, y_min);
		}
	//}
}

void	scaling_adjustment_y_min(t_map map, t_res *res)
{
	float	y_min;

	printf("Pos Y : %d Pos X : %d\n", map.y, map.x);
	y_min = res->y0 - map.map[map.y][map.x] * res->z_scale + \
			(map.x + map.y) * fabs(res->y_scale * sin(ALPHA));
	if (y_min < 100)
		res->z_scale *= 0.9;
	if (y_min > 100)
		res->z_scale *= 1.1;
}

void	scaling_adjustment_y_max(t_map map, t_txt_map txt, t_res *res)
{
	float	y_max;

	y_max = res->y0 + (map.nb + txt.nbline) * fabs(res->y_scale * sin(ALPHA));
	if (y_max < (res->y - 150))
		res->y_scale *= 1.1;
	if (y_max > (res->y - 150))
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
	if (x_min > 150)
		res->x0 *= 0.9;
	if (x_min < 150)
		res->x0 *= 1.1;
}
