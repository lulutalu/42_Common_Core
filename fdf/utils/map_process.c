/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:36:10 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/23 16:45:24 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	nl_counter(t_fdf *fdf, t_file file)
{
	fdf->txt.nbline = 0;
	while (fdf->txt.line != NULL)
	{
		fdf->txt.line = get_next_line(file.fd);
		fdf->txt.nbline++;
	}
	free(fdf->txt.line);
}

void	array_filling(t_fdf *fdf, t_file file)
{
	fdf->txt.x = 0;
	while (fdf->txt.x < (fdf->txt.nbline - 1))
	{
		fdf->txt.line = get_next_line(file.fd);
		fdf->txt.line = ft_dyn_substr(&fdf->txt.line, \
				0, ft_strlen(fdf->txt.line) - 1);
		fdf->txt.array[fdf->txt.x] = ft_calloc(\
				(ft_strlen(fdf->txt.line) + 1), sizeof(char));
		mem_alloc_check(fdf->txt.array[fdf->txt.x]);
		fdf->txt.y = 0;
		while (fdf->txt.line[fdf->txt.y])
		{
			fdf->txt.array[fdf->txt.x][fdf->txt.y] = fdf->txt.line[fdf->txt.y];
			fdf->txt.y++;
		}
		fdf->txt.x++;
		free(fdf->txt.line);
	}
}

void	file_digit_check(t_fdf *fdf)
{
	fdf->txt.x = 0;
	while (fdf->txt.x < (fdf->txt.nbline - 1))
	{
		fdf->txt.y = 0;
		while (fdf->txt.array[fdf->txt.x][fdf->txt.y])
		{
			if (!((fdf->txt.array[fdf->txt.x][fdf->txt.y] >= '0' \
						&& fdf->txt.array[fdf->txt.x][fdf->txt.y] <= '9') \
						|| fdf->txt.array[fdf->txt.x][fdf->txt.y] == '-' \
						|| fdf->txt.array[fdf->txt.x][fdf->txt.y] == ' ' \
						|| fdf->txt.array[fdf->txt.x][fdf->txt.y] == '\0' \
						|| fdf->txt.array[fdf->txt.x][fdf->txt.y] == '\n'))
			{
				ft_putendl_fd(NOT_DIGIT, 2);
				exit(EXIT_FAILURE);
			}
			else
				fdf->txt.y++;
		}
		fdf->txt.x++;
	}
}

void	int_array(t_fdf *fdf)
{
	fdf->map.map = ft_calloc((fdf->txt.nbline + 1), sizeof(int *));
	mem_alloc_check(fdf->map.map);
	fdf->txt.x = 0;
	fdf->map.x = 0;
	while (fdf->txt.x < (fdf->txt.nbline - 1))
	{
		fdf->map.splited = ft_split(fdf->txt.array[fdf->txt.x], ' ');
		fdf->map.nb = 0;
		while (fdf->map.splited[fdf->map.nb])
			fdf->map.nb++;
		fdf->map.map[fdf->map.x] = ft_calloc(fdf->map.nb, sizeof(int));
		mem_alloc_check(fdf->map.map[fdf->map.x]);
		fdf->map.nb = 0;
		fdf->map.y = 0;
		int_array_2(fdf);
		free(fdf->txt.array[fdf->txt.x]);
		free(fdf->map.splited);
		fdf->txt.x++;
		fdf->map.x++;
	}
}

void	int_array_2(t_fdf *fdf)
{
	while (fdf->map.splited[fdf->map.nb])
	{
		fdf->map.map[fdf->map.x][fdf->map.y] \
			= ft_atoi(fdf->map.splited[fdf->map.nb]);
		fdf->map.y++;
		fdf->map.nb++;
	}
}
