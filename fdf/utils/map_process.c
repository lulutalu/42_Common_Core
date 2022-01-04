/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:36:10 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/04 18:21:41 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	nl_counter(t_map *map, t_file file)
{
	map->nbline = 0;
	while (map->line != NULL)
	{
		map->line = get_next_line(file.fd);
		map->nbline++;
	}
	free(map->line);
}

void	array_filling(t_map *map, t_file file)
{
	map->x = 0;
	while (map->x < (map->nbline - 1))
	{
		map->line = get_next_line(file.fd);
		map->array[map->x] = ft_calloc((ft_strlen(map->line) + 1), sizeof(char));
		map->y = 0;
		while (map->line[map->y])
		{
			map->array[map->x][map->y] = map->line[map->y];
			map->y++;
		}
		map->x++;
	}
}
