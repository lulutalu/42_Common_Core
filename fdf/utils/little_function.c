/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:47 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/20 16:04:52 by lduboulo         ###   ########.fr       */
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

int	color_selection(t_coord coord)
{
	if (coord.final->z == coord.start->z && coord.final->z != 0)
		return (BLUE);
	if (coord.final->z != coord.start->z && (coord.final->z > 0 \
				|| coord.start->z > 0))
		return (PURPLE);
	if (coord.final->z != coord.start->z && (coord.final->z < 0 \
				|| coord.start->z < 0))
		return (RED);
	if (coord.final->z == coord.start->z && coord.final->z == 0)
		return (WHITE);
	else
		return (WHITE);
}
