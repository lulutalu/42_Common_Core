/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_drawing_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:02:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/20 16:33:18 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_mlx mlx, t_coord coord, int color, t_res res)
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
		if ((line.x <= res.x && line.x >= 0) && \
				(line.y <= res.y && line.y >= 0))
			my_mlx_pixel_put(&mlx, &line, color);
		line.x += line.delta_x;
		line.y += line.delta_y;
		line.len--;
	}
}

void	y_axis_algorithm(t_mlx mlx, t_txt_map txt, t_map *map, t_res *res)
{
	t_coord	coord;

	coord.start = malloc(sizeof(coord));
	coord.final = malloc(sizeof(coord));
	map->y = 0;
	while (map->y < (txt.nbline - 1))
	{
		map->x = 0;
		while (map->x < (map->nb - 1))
		{
			coord.start->x = res->x0 + ((map->y * -1 + map->x) * \
					fabs(res->x_scale * cos(ALPHA)));
			coord.start->y = res->y0 + ((map->y + map->x) * \
					fabs(res->y_scale * sin(ALPHA)));
			coord.start->z = map->map[map->y][map->x++];
			coord.final->z = map->map[map->y][map->x];
			y_axis_draw(&coord, *res);
			print_line(mlx, coord, color_selection(coord), *res);
		}	
		map->y++;
	}
}

void	y_axis_draw(t_coord *coord, t_res res)
{
	if (coord->start->z == 0 && coord->final->z == 0)
	{
		coord->final->x = coord->start->x + fabs(res.x_scale * cos(ALPHA));
		coord->final->y = coord->start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (coord->start->z == coord->final->z)
	{
		coord->final->x = coord->start->x + fabs(res.x_scale * cos(ALPHA));
		coord->start->y -= res.z_scale * coord->start->z;
		coord->final->y = coord->start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (coord->start->z != coord->final->z)
	{
		coord->final->x = coord->start->x + fabs(res.x_scale * cos(ALPHA));
		coord->final->y = coord->start->y + fabs(res.y_scale * sin(ALPHA)) \
					- (res.z_scale * coord->final->z);
		coord->start->y -= res.z_scale * coord->start->z;
	}
}

void	x_axis_algorithm(t_mlx mlx, t_txt_map txt, t_map *map, t_res *res)
{
	t_coord	coord;

	coord.start = malloc(sizeof(coord));
	coord.final = malloc(sizeof(coord));
	map->x = 0;
	while (map->x < map->nb)
	{
		map->y = 0;
		while (map->y < (txt.nbline - 2))
		{
			coord.start->x = res->x0 + ((map->y * -1 + map->x) \
					* fabs(res->x_scale * cos(ALPHA)));
			coord.start->y = res->y0 + ((map->y + map->x) * \
					fabs(res->y_scale * sin(ALPHA)));
			coord.start->z = map->map[map->y++][map->x];
			coord.final->z = map->map[map->y][map->x];
			x_axis_draw(&coord, *res);
			print_line(mlx, coord, color_selection(coord), *res);
		}
		map->x++;
	}
}

void	x_axis_draw(t_coord *coord, t_res res)
{
	if (coord->start->z == 0 && coord->final->z == 0)
	{
		coord->final->x = coord->start->x - fabs(res.x_scale * cos(ALPHA));
		coord->final->y = coord->start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (coord->start->z == coord->final->z)
	{
		coord->final->x = coord->start->x - fabs(res.x_scale * cos(ALPHA));
		coord->start->y -= res.z_scale * coord->start->z;
		coord->final->y = coord->start->y + fabs(res.y_scale * sin(ALPHA));
	}
	else if (coord->start->z != coord->final->z)
	{
		coord->final->x = coord->start->x - fabs(res.x_scale * cos(ALPHA));
		coord->final->y = coord->start->y + fabs(res.y_scale * sin(ALPHA)) \
					- (res.z_scale * coord->final->z);
		coord->start->y -= res.z_scale * coord->start->z;
	}
}
