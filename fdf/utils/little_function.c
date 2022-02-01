/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:47 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/01 14:35:24 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mem_alloc_check(void *ptr)
{
	if (ptr == NULL)
	{
		free(ptr);
		ft_putendl_fd(ALLOC_ER, 2);
		exit(EXIT_FAILURE);
	}
}

int	color_selection(t_coord start, t_coord final)
{
	if (final.z == start.z && final.z != 0)
		return (BLUE);
	if (final.z != start.z && (final.z > 0 || start.z > 0))
		return (PURPLE);
	if (final.z != start.z && (final.z < 0 || start.z < 0))
		return (RED);
	if (final.z == start.z && final.z == 0)
		return (WHITE);
	else
		return (WHITE);
}

float	mean_value_tab(t_map map, t_txt_map txt)
{
	int		y;
	int		x;
	float	mean;

	mean = 0;
	y = 0;
	while (y < (txt.nbline - 1))
	{
		x = 0;
		while (x < map.nb)
		{
			mean += map.map[y][x];
			x++;
		}
		y++;
	}
	mean /= x * y;
	return (mean);
}

void	find_z_critical(t_map *map, t_txt_map txt, float mean)
{
	int	x;
	int	y;
	int	temp;

	temp = (int)mean;
	y = 0;
	while (y < (txt.nbline - 1))
	{
		x = 0;
		while (x < map->nb)
		{
			if (map->map[y][x] > mean && map->map[y][x] > temp)
			{
				map->y = y;
				map->x = x;
				temp = map->map[y][x];
			}
			x++;
		}
		if (map->y == y)
			break ;
		y++;
	}
	if (y == (txt.nbline - 1) && x == map->nb)
	{
		map->y = 0;
		map->x = 0;
	}
	printf("Pos x : %d Pos y : %d\n", map->x, map->y);
}

void	find_max_z_value(t_map *map, t_txt_map txt, float mean)
{
	int	x;
	int	y;
	int	max;

	max = -1000;
	y = 0;
	while (y < (txt.nbline - 1))
	{
		x = 0;
		while (x < map->nb)
		{
			if (map->map[y][x] > max && map->map[y][x] > (int)mean)
			{
				max = map->map[y][x];
				map->y = y;
				map->x = x;
			}
			x++;
		}
		y++;
	}
	printf("Value max : %d Pos y : %d Pos x : %d\n", max, map->y, map->x);
}
