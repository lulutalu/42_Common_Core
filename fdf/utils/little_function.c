/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:47 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/22 18:31:15 by lduboulo         ###   ########.fr       */
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
