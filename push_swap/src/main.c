/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/13 22:04:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_double	dl;
	t_node		*ahead;
	t_node		*bhead;
	int			temp;
	int			i;
	t_node		*acur;
	t_node		*bcur;
	t_node		*big;
	t_node		*curbig;

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
		n_3_sort(&ahead, dl.ymax);
	else if (dl.ymax == 5)
		n_5_sort(&ahead, &bhead, dl.ymax);
	else
	{
//		stack_visualisation(&ahead, &bhead);
		i = 1;
		while (i++ <= dl.ymax / 2)
			push_stack_b(&ahead, &bhead);
//		stack_visualisation(&ahead, &bhead);	
		bcur = bhead;
		big = bcur;
		i = 0;
		temp = 0;
		while (bcur != NULL) //find the biggest pos of all
		{
			if (bcur->pos > bbig->pos)
			{
				bbig = bcur;
				temp = i;
			}
			i++;
			bcur = bcur->next;
		}
		linked_list_circle(&bhead);
		bcur = bhead;
		while (bcur->prev->pos != big->pos) //bring the biggest at the end
		{
			if (temp <= dl.ymax / 4)
				rotate_stack(&bhead, 'b');
			else
				reverse_rotate_stack(&bhead, 'b');
			linked_list_circle(&bhead);
			bcur = bhead;
		}
//		stack_visualisation(&ahead, &bhead);
		linked_list_linear(&bhead);
		while (invert_check_sort(&bhead) == 0)
		{
			i = 0;
			curbig = bhead;
			bcur = bhead;
			while (bcur != NULL) //find the biggest of not process values
			{
				if (bcur->pos > curbig->pos && bcur->pos < big->pos)
					curbig = bcur;
				bcur = bcur->next;
				i++;
			}
			if (i <= dl.ymax / 4)
			{
				while (bhead->pos != curbig->pos)
             		rotate_stack(&bhead, 'b');
			}
			else
			{
				while (bhead->pos != curbig->pos)
					reverse_rotate_stack(&bhead, 'b');
			}
			if (curbig->next->pos == big->pos)
				swap_stack(&bhead, 'b');	
			else
			{
				while (bhead->next->pos != big->pos)
				{
					swap_stack(&bhead, 'b');
					rotate_stack(&bhead, 'b');
				}
				swap_stack(&bhead, 'b');	
			}
			big = curbig;
			reverse_rotate_stack(&bhead, 'b');
			reverse_rotate_stack(&bhead, 'b');
//			stack_visualisation(&ahead, &bhead);
		}
	}
	if (bhead == NULL)
		return (check_sort(&ahead));
	else
		return (0);
}
