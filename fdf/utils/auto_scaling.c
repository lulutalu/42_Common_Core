/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_scaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:56:43 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/22 19:10:50 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling_adjustment(t_fdf *fdf)
{
	float	x_max;
	float	x_min;
	float	y_max;

	x_max = 500;
	x_min = 500;
	while ((x_max > (fdf->res.x - 50) || x_max < (fdf->res.x - 150)) \
			|| (x_min > 250 || x_min < 75))
	{
		scaling_adjustment_x_max(fdf);
		scaling_adjustment_x0(fdf);
		x_max = fdf->res.x0 + fdf->map.nb * fabs(fdf->res.x_scale * cos(fdf->res.alpha));
		x_min = fdf->res.x0 - (fdf->txt.nbline - 1) * fabs(fdf->res.x_scale * cos(fdf->res.alpha));
	}
	y_max = 100;
	while (y_max < (fdf->res.y - 200) || y_max > (fdf->res.y - 100))
	{
		scaling_adjustment_y_max(fdf);
		y_max = fdf->res.y0 + (fdf->map.nb + fdf->txt.nbline) \
				* fabs(fdf->res.y_scale * sin(fdf->res.alpha));
	}
}

void	scaling_adjustment_y_max(t_fdf *fdf)
{
	float	y_max;

	y_max = fdf->res.y0 + (fdf->map.nb + fdf->txt.nbline) * fabs(fdf->res.y_scale * sin(fdf->res.alpha));
	if (y_max < (fdf->res.y - 150))
		fdf->res.y_scale *= 1.1;
	if (y_max > (fdf->res.y - 150))
		fdf->res.y_scale *= 0.9;
}

void	scaling_adjustment_x_max(t_fdf *fdf)
{
	float	x_max;

	x_max = fdf->res.x0 + fdf->map.nb * fabs(fdf->res.x_scale * cos(fdf->res.alpha));
	if (x_max < (fdf->res.x - 100))
		fdf->res.x_scale *= 1.1;
	if (x_max > (fdf->res.x - 100))
		fdf->res.x_scale *= 0.9;
}

void	scaling_adjustment_x0(t_fdf *fdf)
{
	float	x_min;

	x_min = fdf->res.x0 - (fdf->txt.nbline - 1) * fabs(fdf->res.x_scale * cos(fdf->res.alpha));
	if (x_min > 150)
		fdf->res.x0 *= 0.9;
	if (x_min < 150)
		fdf->res.x0 *= 1.1;
}
