/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:36:10 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/05 15:13:00 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	nl_counter(t_txt_map *txt, t_file file)
{
	txt->nbline = 0;
	while (txt->line != NULL)
	{
		txt->line = get_next_line(file.fd);
		txt->nbline++;
	}
	free(txt->line);
}

void	array_filling(t_txt_map *txt, t_file file)
{
	txt->x = 0;
	while (txt->x < (txt->nbline - 1))
	{
		txt->line = get_next_line(file.fd);
		txt->array[txt->x] = ft_calloc((ft_strlen(txt->line) + 1), sizeof(char));
		txt->y = 0;
		while (txt->line[txt->y])
		{
			txt->array[txt->x][txt->y] = txt->line[txt->y];
			txt->y++;
		}
		txt->x++;
	}
}

void	file_digit_check(t_txt_map *txt)
{
	txt->x = 0;
	while (txt->x < (txt->nbline - 1))
	{
		txt->y = 0;
		while (txt->array[txt->x][txt->y])
		{
			if (!((txt->array[txt->x][txt->y] >= '0' \
						&& txt->array[txt->x][txt->y] <= '9') \
						|| txt->array[txt->x][txt->y] == '-' \
						|| txt->array[txt->x][txt->y] == ' ' \
						|| txt->array[txt->x][txt->y] == '\0' \
						|| txt->array[txt->x][txt->y] == '\n'))
			{
				ft_putendl_fd(NOT_DIGIT, 2);
				exit(EXIT_FAILURE);
			}
			else
				txt->y++;
		}
		txt->x++;
	}
}
