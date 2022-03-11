/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/12 00:04:04 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_double	dl;
	t_node		*ahead;
	t_node		*bhead;
	t_node		*acur;
	t_node		*bcur;
	int			i;
	int			comp;

	dl = check_of_args(argc, argv);
	ahead = NULL;
	bhead = NULL;
	dl.y = 0;
	while (dl.y < dl.ymax)
		lst_add(&ahead, dl.tab[dl.y++]);
	if (argc > 2)
		value_listing(&ahead, argc);
	else
		value_listing(&ahead, dl.ymax + 1);	
	if (dl.ymax == 3 || dl.ymax == 2)
		n_3_sort(&ahead);
	stack_visualisation(&ahead, &bhead);
	if (dl.ymax == 5)
	{
		i = 3;
		while (i-- > 0)
		{
			linked_list_circle(&ahead);
			acur = ahead;
			bcur = bhead;
			if (acur->next->pos == 5 && acur->next->next != ahead)
			{
				swap_stack(&ahead, 'a');
				rotate_stack(&ahead, 'a');
			}
			else if (acur->pos == 4)
			{
				while (acur->pos != 5)
				{
					comp = dl.ymax - 1;
					if (acur->pos == 1)
						swap_stack(&ahead, 'a');
					push_stack_b(&ahead, &bhead);
					bcur = bhead;
					acur = ahead;
					stack_visualisation(&ahead, &bhead);
				}
				while (bcur != NULL)
				{
					while (bcur->pos != comp)
					{
						rotate_stack(&bhead, 'b');
						stack_visualisation(&ahead, &bhead);
						bcur = bhead;
					}
					push_stack_a(&ahead, &bhead);
					stack_visualisation(&ahead, &bhead);
					bcur = bhead;
					comp--;
				}
				reverse_rotate_stack(&ahead, 'a');
				stack_visualisation(&ahead, &bhead);
				acur = ahead;
				if (acur->pos == 1)
				{
					reverse_rotate_stack(&ahead, 'a');
					swap_stack(&ahead, 'a');
					stack_visualisation(&ahead, &bhead);
				}
				else if (acur->pos == 2)
					reverse_rotate_stack(&ahead, 'a');
			}
			stack_visualisation(&ahead, &bhead);
			if (bhead == NULL)
				check_sort(&ahead);
		}
	}
}
