/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:13:23 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/28 15:11:54 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double	double_arg_n(int argc, char **argv)
{
	t_double	dl;

	dl.ymax = argc - 1;
	dl.tab = ft_calloc(dl.ymax + 1, sizeof(int));
	ft_mem_alloc_check(dl.tab);
	dl.y = 0;
	while (dl.y < dl.ymax)
	{
		limits_check(ft_atol(argv[dl.y + 1]));
		dl.tab[dl.y] = ft_atoi(argv[dl.y + 1]);
		dl.y++;
	}
	double_arg_tab_check(&dl);
	return (dl);
}

void	limits_check(long value)
{
	if (value > INT_MAX || value < INT_MIN)
		error_exit(LIMITS);
}
