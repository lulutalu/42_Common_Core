/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/14 23:48:16 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_double	dl;
	t_node		*ahead;
	t_node		*bhead;
	int			i;
	t_proc		bproc;
	t_proc		aproc;

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
		//////////////////////////////////////////////////
		i = 1;
		while (i++ <= dl.ymax / 2)
			push_stack_b(&ahead, &bhead);
		/////////////////////////////////////////////////
		find_mini_value(&ahead, &aproc);
		find_biggest_value(&bhead, &bproc);
//		stack_visualisation(&ahead, &bhead);
		linked_list_circle(&bhead);
		linked_list_circle(&ahead);
		while (bhead->prev->pos != bproc.aim->pos || ahead->prev->pos != aproc.aim->pos)
		{
			if (bhead->prev->pos != bproc.aim->pos && ahead->prev->pos != aproc.aim->pos)
			{
				if (bproc.temp <= dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
					rotate_both(&ahead, &bhead);
				else if (bproc.temp > dl.ymax / 4 && aproc.temp > dl.ymax / 4)
					reverse_rotate_both(&ahead, &bhead);
				else if (bproc.temp <= dl.ymax / 4 && aproc.temp > dl.ymax / 4)
				{
					rotate_stack(&bhead, 'b');
					reverse_rotate_stack(&ahead, 'a');
				}
				else if (bproc.temp > dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
				{
					reverse_rotate_stack(&bhead, 'b');
					rotate_stack(&ahead, 'a');
				}
			}
			else if (bhead->prev->pos == bproc.aim->pos)
			{
				if (aproc.temp <= dl.ymax / 4)
					rotate_stack(&ahead, 'a');
				else
					reverse_rotate_stack(&ahead, 'a');
			}
			else if (ahead->prev->pos == aproc.aim->pos)
			{
				if (bproc.temp <= dl.ymax / 4)
					rotate_stack(&bhead, 'b');
				else
					reverse_rotate_stack(&bhead, 'b');
			}
//			stack_visualisation(&ahead, &bhead);
			linked_list_circle(&bhead);
			linked_list_circle(&ahead);
		}
		///////////////////////////////////////////////////////////////////////////
		linked_list_linear(&bhead);
		linked_list_linear(&ahead);
//		while (invert_check_sort(&bhead) == 0 || check_sort(&ahead) == 0)
		i = 1;
		while (i-- > 0)
		{
			stack_visualisation(&ahead, &bhead);
			linked_list_linear(&ahead);
			linked_list_linear(&bhead);
			find_next_big(&bhead, &bproc);
			find_next_mini(&ahead, &aproc);
			printf("Aim for a : %d\n Aim for b : %d\n", aproc.curaim->value, bproc.curaim->value);
			printf("a : %d\n b : %d\n", aproc.temp, bproc.temp);
			if (bproc.temp <= dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
			{
				while (bhead->pos != bproc.curaim->pos && ahead->pos != aproc.curaim->pos)
             		rotate_both(&ahead, &bhead);
				if (bhead->pos == bproc.curaim->pos)
				{
					while (ahead->pos != aproc.curaim->pos)
						rotate_stack(&ahead, 'a');
				}
				if (ahead->pos == bproc.curaim->pos)
				{
					while (bhead->pos != bproc.curaim->pos)
						rotate_stack(&bhead, 'b');
				}
				stack_visualisation(&ahead, &bhead);
			}
			else if (bproc.temp > dl.ymax / 4 && aproc.temp > dl.ymax / 4)
			{
				while (bhead->pos != bproc.curaim->pos && ahead->pos != aproc.curaim->pos)
					reverse_rotate_both(&ahead, &bhead);
				if (bhead->pos == bproc.curaim->pos)
				{
					while (ahead->pos != aproc.curaim->pos)
						reverse_rotate_stack(&ahead, 'a');
				}
				if (ahead->pos == aproc.curaim->pos)
				{
					while (bhead->pos != bproc.curaim->pos)
						reverse_rotate_stack(&bhead, 'b');
				}
				stack_visualisation(&ahead, &bhead);
			}
			else if (bproc.temp <= dl.ymax / 4 && aproc.temp > dl.ymax / 4)
			{
				while (bhead->pos != bproc.curaim->pos && ahead->pos != aproc.curaim->pos)
				{
					rotate_stack(&bhead, 'b');
					reverse_rotate_stack(&ahead, 'a');
				}
				if (bhead->pos == bproc.curaim->pos)
				{
					while (ahead->pos != aproc.curaim->pos)
						reverse_rotate_stack(&ahead, 'a');
				}
				if (ahead->pos == aproc.curaim->pos)
				{
					while (bhead->pos != bproc.curaim->pos)
						rotate_stack(&bhead, 'b');
				}
				stack_visualisation(&ahead, &bhead);
			}
			else if (bproc.temp > dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
			{
				while (bhead->pos != bproc.curaim->pos && ahead->pos != aproc.curaim->pos)
				{
					reverse_rotate_stack(&bhead, 'b');
					rotate_stack(&ahead, 'a');
				}
				if (bhead->pos == bproc.curaim->pos)
				{
					while (ahead->pos != aproc.curaim->pos)
						rotate_stack(&ahead, 'a');
				}
				if (ahead->pos == aproc.curaim->pos)
				{
					while (bhead->pos != bproc.curaim->pos)
						reverse_rotate_stack(&bhead, 'b');
				}
				stack_visualisation(&ahead, &bhead);
			}	
			if (bhead->pos == bproc.curaim->pos && ahead->pos == aproc.curaim->pos)
			{
				while (bhead->next->pos != bproc.aim->pos && ahead->next->pos != aproc.aim->pos)
				{
					swap_both(&ahead, &bhead);
					rotate_both(&ahead, &bhead);
				}
				if (bhead->next->pos == bproc.aim->pos)
				{
					while (ahead->next->pos != aproc.aim->pos)
					{
						swap_stack(&ahead, 'a');
						rotate_stack(&ahead, 'a');
					}
				}
				else if (ahead->next->pos == aproc.aim->pos)
				{
					while (bhead->next->pos != bproc.aim->pos)
					{
						swap_stack(&bhead, 'b');
						rotate_stack(&bhead, 'b');
					}
				}
				stack_visualisation(&ahead, &bhead);
				swap_both(&ahead, &bhead);
			}
			bproc.aim = bproc.curaim;
			aproc.aim = aproc.curaim;
			/*find_lst(&ahead, aproc.limit, &aproc);
			find_lst(&bhead, bproc.limit, &bproc);
			if (aproc.i <= dl.ymax / 4 && bproc.i <= dl.ymax / 4)
			{
				while (ahead != aproc.limit && bhead != bproc.limit)
					rotate_both(&ahead, &bhead);
				if (ahead == aproc.limit)
				{
					while (bhead != bproc.limit)
						rotate_stack(&bhead, 'b');
				}
				if (bhead == bproc.limit)
				{
					while (ahead != aproc.limit)
						rotate_stack(&ahead, 'a');
				}
			}
			else if (aproc.i > dl.ymax / 4 && bproc.i > dl.ymax / 4)
			{
				while (ahead != aproc.limit && bhead != bproc.limit)
					reverse_rotate_both(&ahead, &bhead);
				if (ahead == aproc.limit)
				{
					while (bhead != bproc.limit)
						reverse_rotate_stack(&bhead, 'b');
				}
				if (bhead == bproc.limit)
				{
					while (ahead != aproc.limit)
						reverse_rotate_stack(ahead, 'a');
				}
			}
			else if (aproc.i > dl.ymax / 4 && bproc.i <= dl.ymax / 4)
			{
				while (
			}*/
			stack_visualisation(&ahead, &bhead);
		}
//		stack_visualisation(&ahead, &bhead);
		/////////////////////////////////////////////////////////////
/*		while (bhead != NULL)
		{
			if (bhead->pos > ahead->pos)
			{
				push_stack_a(&ahead, &bhead);
				rotate_stack(&ahead, 'a');
			}
			else if (bhead->pos < ahead->pos)
		}*/
	}
	if (bhead == NULL)
		return (check_sort(&ahead));
	else
		return (0);
}
