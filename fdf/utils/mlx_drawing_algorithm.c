/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drawing_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/21 19:37:19 by lduboulo         ###   ########.fr       */
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
		if (final.z == start.z && final.z != 0)
			my_mlx_pixel_put(&mlx, &line, BLUE);
		if (final.z != start.z && (final.z > 0 || start.z > 0))
			my_mlx_pixel_put(&mlx, &line, PURPLE);
		if (final.z != start.z && (final.z < 0 || start.z < 0))
			my_mlx_pixel_put(&mlx, &line, RED);
		if (final.z == start.z && final.z == 0)
			my_mlx_pixel_put(&mlx, &line, WHITE);
		line.x += line.delta_x;
		line.y += line.delta_y;
		line.len--;
	}
}

void	y_axis_algorithm(t_mlx mlx, t_txt_map txt, t_map *map, t_res res)
{
	t_coord	start;
	t_coord	final;

	while (map->y < (txt.nbline - 1))
	{
		map->x = 0;
		while (map->x < (map->nb - 1))
		{
			start.x = (res.x / 2) + ((map->y * -1 + map->x) * \
					fabs(res.x_scale * cos(ALPHA)));
			start.y = 400 + ((map->y + map->x) * \
					fabs(res.y_scale * sin(ALPHA)));
			start.z = map->map[map->y][map->x++];
			final.z = map->map[map->y][map->x];
			y_axis_draw(&start, &final, res);
			print_line(mlx, start, final);
		}
		map->y++;
	}
}

void	y_axis_draw(t_coord *start, t_coord *final, t_res res)
{
	if (start->z == 0 && final->z == 0)
	{
		final->x = start->x + fabs(res.x_scale * cos(ALPHA));
		final->y = start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (start->z == final->z)
	{
		final->x = start->x + fabs(res.x_scale * cos(ALPHA));
		start->y -= res.z_scale * start->z;
		final->y = start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (start->z != final->z)
	{
		final->x = start->x + fabs(res.x_scale * cos(ALPHA));
		final->y = start->y + fabs(res.y_scale * sin(ALPHA)) \
					- (res.z_scale * final->z);
		start->y -= res.z_scale * start->z;
	}
}

void	x_axis_algorithm(t_mlx mlx, t_txt_map txt, t_map *map, t_res res)
{
	t_coord	start;
	t_coord	final;

	while (map->x < map->nb)
	{
		map->y = 0;
		while (map->y < (txt.nbline - 2))
		{
			start.x = (res.x / 2) + ((map->y * -1 + map->x) \
					* fabs(res.x_scale * cos(ALPHA)));
			start.y = 400 + ((map->y + map->x) * \
					fabs(res.y_scale * sin(ALPHA)));
			start.z = map->map[map->y++][map->x];
			final.z = map->map[map->y][map->x];
			x_axis_draw(&start, &final, res);
			print_line(mlx, start, final);
		}
		map->x++;
	}
}

void	x_axis_draw(t_coord *start, t_coord *final, t_res res)
{
	if (start->z == 0 && final->z == 0)
	{
		final->x = start->x - fabs(res.x_scale * cos(ALPHA));
		final->y = start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (start->z == final->z)
	{
		final->x = start->x - fabs(res.x_scale * cos(ALPHA));
		start->y -= res.z_scale * start->z;
		final->y = start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (start->z != final->z)
	{
		final->x = start->x - fabs(res.x_scale * cos(ALPHA));
		final->y = start->y + fabs(res.y_scale * sin(ALPHA)) \
					- (res.z_scale * final->z);
		start->y -= res.z_scale * start->z;
	}
}
