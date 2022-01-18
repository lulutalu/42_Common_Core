/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drawing_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/18 22:23:47 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_mlx mlx, t_coord start, t_coord final)
{
	t_line	line;

	line.x = start.x;
	line.y = start.y;
	line.delta_x = final.x - start.x;
	line.delta_y = final.y - start.y;
	line.len = sqrt((line.delta_x * line.delta_x) \
			+ (line.delta_y * line.delta_y));
	line.delta_x /= line.len;
	line.delta_y /= line.len;
	while (line.len > 0)
	{
		if (final.z == start.z && final.z > 0)
			my_mlx_pixel_put(&mlx, &line, BLUE);
		if (final.z != start.z)
			my_mlx_pixel_put(&mlx, &line, PURPLE);
		if (final.z == start.z && final.z == 0)
			my_mlx_pixel_put(&mlx, &line, WHITE);
		line.x += line.delta_x;
		line.y += line.delta_y;
		line.len--;
	}
}
