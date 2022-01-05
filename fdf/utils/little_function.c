/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:47 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/05 22:19:31 by lduboulo         ###   ########.fr       */
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
