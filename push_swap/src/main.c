/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/28 15:07:02 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_double	dl;
	t_node		*ahead;
	t_node		*bhead;

	dl = check_of_args(argc, argv);
	ahead = NULL;
	bhead = NULL;
	dl.y = 0;
	while (dl.y < dl.ymax)
		lst_add(&ahead, dl.tab[dl.y++]);
	free(dl.tab);
	if (argc > 2)
		value_listing(&ahead, argc);
	else
		value_listing(&ahead, dl.ymax + 1);
	if ((dl.ymax == 3 || dl.ymax == 2) && check_sort(&ahead) == 0)
		n_3_sort(&ahead, dl.ymax);
	else if (dl.ymax == 5 && check_sort(&ahead) == 0)
		n_5_sort(&ahead, &bhead, dl.ymax);
	else if (check_sort(&ahead) == 0)
		n_sort(&ahead, &bhead, dl.ymax);
	if (bhead == NULL && check_sort(&ahead) == 1)
		lst_del(&ahead, 1);
	else
		lst_del(&ahead, 0);
}
