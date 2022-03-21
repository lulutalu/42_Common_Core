/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/21 18:10:32 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_double	dl;
	t_node		*ahead;
	t_node		*bhead;
	int			i;
	int			chunk;
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
		i = 0;
		while (i++ < dl.ymax / 2)
		{
			push_stack_b(&ahead, &bhead);
/*			while (ahead->pos <= dl.ymax / 2)
				rotate_stack(&ahead, 'a');
			if (ahead->pos > dl.ymax / 2)
				push_stack_b(&ahead, &bhead);
			i++;*/
		}
		/////////////////////////////////////////////////
		find_mini_value(&ahead, &aproc);
		find_biggest_value(&bhead, &bproc);
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
			linked_list_circle(&bhead);
			linked_list_circle(&ahead);
		}
//		stack_visualisation(&ahead, &bhead);
		///////////////////////////////////////////////////////////////////////////
		linked_list_linear(&bhead);
		linked_list_linear(&ahead);
//		while (invert_check_sort(&bhead) == 0 || check_sort(&ahead) == 0)
		i = 0;
		chunk = 10;
		while (i < chunk)
		{
			linked_list_linear(&ahead);
			linked_list_linear(&bhead);
			find_next_big(&bhead, &bproc);	
			find_next_mini(&ahead, &aproc);
//			printf("Target a : %d\nTarget b : %d\n", aproc.curaim->pos, bproc.curaim->pos);
//			/////////////////////////////////////////////////////////////////////////
			if (bproc.temp <= dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
			{
				while (bhead != bproc.curaim && ahead != aproc.curaim)
             		rotate_both(&ahead, &bhead);
				if (bhead == bproc.curaim)
				{
					while (ahead != aproc.curaim)
						rotate_stack(&ahead, 'a');
				}
				if (ahead == aproc.curaim)
				{
					while (bhead != bproc.curaim)
						rotate_stack(&bhead, 'b');
				}
			}
			else if (bproc.temp > dl.ymax / 4 && aproc.temp > dl.ymax / 4)
			{
				while (bhead != bproc.curaim && ahead != aproc.curaim)
					reverse_rotate_both(&ahead, &bhead);
				if (bhead == bproc.curaim)
				{
					while (ahead != aproc.curaim)
						reverse_rotate_stack(&ahead, 'a');
				}
				if (ahead == aproc.curaim)
				{
					while (bhead != bproc.curaim)
						reverse_rotate_stack(&bhead, 'b');
				}
			}
			else if (bproc.temp <= dl.ymax / 4 && aproc.temp > dl.ymax / 4)
			{
				while (bhead != bproc.curaim && ahead != aproc.curaim)
				{
					rotate_stack(&bhead, 'b');
					reverse_rotate_stack(&ahead, 'a');
				}
				if (bhead == bproc.curaim)
				{
					while (ahead != aproc.curaim)
						reverse_rotate_stack(&ahead, 'a');
				}
				if (ahead == aproc.curaim)
				{
					while (bhead != bproc.curaim)
						rotate_stack(&bhead, 'b');
				}
			}
			else if (bproc.temp > dl.ymax / 4 && aproc.temp <= dl.ymax / 4)
			{
				while (bhead != bproc.curaim && ahead != aproc.curaim)
				{
					reverse_rotate_stack(&bhead, 'b');
					rotate_stack(&ahead, 'a');
				}
				if (bhead == bproc.curaim)
				{
					while (ahead != aproc.curaim)
						rotate_stack(&ahead, 'a');
				}
				if (ahead == aproc.curaim)
				{
					while (bhead != bproc.curaim)
						reverse_rotate_stack(&bhead, 'b');
				}
			}
			///////////////////////////////////////////////////////////////
			if (bhead == bproc.curaim && ahead == aproc.curaim)
			{
				find_lst(&ahead, aproc.aim, &aproc);
				find_lst(&bhead, bproc.aim, &bproc);
//				stack_visualisation(&ahead, &bhead);
//				printf("Temp a : %d\nTemp b : %d\n", aproc.temp, bproc.temp);
//				printf("Comp : %d\n", dl.ymax / 4);
//				printf("Target a : %d\nTarget b : %d\n", aproc.aim->pos, bproc.aim->pos);
				if (aproc.temp <= dl.ymax / 4 && bproc.temp <= dl.ymax / 4)
				{
					while (bhead->next != bproc.aim && ahead->next != aproc.aim)
					{
						swap_both(&ahead, &bhead);
						rotate_both(&ahead, &bhead);
					}
					if (bhead->next == bproc.aim)
					{
						while (ahead->next != aproc.aim)
						{
							swap_stack(&ahead, 'a');
							rotate_stack(&ahead, 'a');
						}
					}
					else if (ahead->next == aproc.aim)
					{
						while (bhead->next != bproc.aim)
						{
							swap_stack(&bhead, 'b');
							rotate_stack(&bhead, 'b');
						}
					}
					swap_both(&ahead, &bhead);
//					stack_visualisation(&ahead, &bhead);
				}
				else if (aproc.temp > dl.ymax / 4 && bproc.temp > dl.ymax / 4)
				{
					linked_list_circle(&ahead);
					linked_list_circle(&bhead);
					while (ahead->prev != aproc.aim && bhead->prev != bproc.aim)
					{
						reverse_rotate_both(&ahead, &bhead);
						swap_both(&ahead, &bhead);
//						stack_visualisation(&ahead, &bhead);
						linked_list_circle(&ahead);
						linked_list_circle(&bhead);
					}
					if (ahead->prev == aproc.aim)
					{
						reverse_rotate_stack(&ahead, 'a');
						while (bhead->prev != bproc.aim)
						{
							reverse_rotate_stack(&bhead, 'b');
							swap_stack(&bhead, 'b');
							linked_list_circle(&bhead);
						}
						if (bhead->prev == bproc.aim)
							reverse_rotate_stack(&bhead, 'b');
					}
					else if (bhead->prev == bproc.aim)
					{
						reverse_rotate_stack(&bhead, 'b');
						while (ahead->prev != aproc.aim)
						{
							reverse_rotate_stack(&ahead, 'a');
							swap_stack(&ahead, 'a');
							linked_list_circle(&ahead);
						}
						if (ahead->prev == aproc.aim)
							reverse_rotate_stack(&ahead, 'a');
					}
//					stack_visualisation(&ahead, &bhead);
				}
				else if (aproc.temp <= dl.ymax / 4 && bproc.temp > dl.ymax / 4)
				{
					linked_list_circle(&bhead);
					while (ahead->next != aproc.aim && bhead->prev != bproc.aim)
					{
						reverse_rotate_stack(&bhead, 'b');
						swap_both(&ahead, &bhead);
						rotate_stack(&ahead, 'a');
						linked_list_circle(&bhead);
					}
					if (ahead->next == aproc.aim)
					{
						swap_stack(&ahead, 'a');
						while (bhead->prev != bproc.aim)
						{
							reverse_rotate_stack(&bhead, 'b');
							swap_stack(&bhead, 'b');
							linked_list_circle(&bhead);
						}
						if (bhead->prev == bproc.aim)
							reverse_rotate_stack(&bhead, 'b');
					}
					else if (bhead->prev == bproc.aim)
					{
						reverse_rotate_stack(&bhead, 'b');
						while (ahead->next != aproc.aim)
						{
							swap_stack(&ahead, 'a');
							rotate_stack(&ahead, 'a');
						}
						if (ahead->next == aproc.aim)
							swap_stack(&ahead, 'a');
					}
//					stack_visualisation(&ahead, &bhead);
				}
				else if (aproc.temp > dl.ymax / 4 && bproc.temp <= dl.ymax / 4)
				{
					linked_list_circle(&ahead);
					while (ahead->prev != aproc.aim && bhead->next != bproc.aim)
					{
						reverse_rotate_stack(&ahead, 'a');
						swap_both(&ahead, &bhead);
						rotate_stack(&bhead, 'b');
//						stack_visualisation(&ahead, &bhead);
						linked_list_circle(&ahead);
					}
					if (bhead->next == bproc.aim)
					{
						reverse_rotate_stack(&ahead, 'a');
						swap_both(&ahead, &bhead);
						while (ahead->prev != aproc.aim)
						{
							reverse_rotate_stack(&ahead, 'a');
							swap_stack(&ahead, 'a');
							linked_list_circle(&ahead);
						}
						if (ahead->prev == aproc.aim)
							reverse_rotate_stack(&ahead, 'a');
					}
					else if (ahead->prev == aproc.aim)
					{
						reverse_rotate_stack(&ahead, 'a');
						while (bhead->next != bproc.aim)
						{
							swap_stack(&bhead, 'b');
							rotate_stack(&bhead, 'b');
						}
						if (bhead->next == bproc.aim)
							swap_stack(&bhead, 'b');
					}
//					stack_visualisation(&ahead, &bhead);
				}
			}
			///////////////////////////////////////////////////////////
//			stack_visualisation(&ahead, &bhead);
			bproc.aim = bproc.curaim;
			aproc.aim = aproc.curaim;
			i++;
		}
		/////////////////////////////////////////////////////////////
//		stack_visualisation(&ahead, &bhead);
/*		find_lst(&ahead, aproc.limit, &aproc);
		find_lst(&bhead, bproc.limit, &bproc);
		if (aproc.temp <= dl.ymax / 4 && bproc.temp <= dl.ymax / 4)
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
		else if (aproc.temp > dl.ymax / 4 && bproc.temp > dl.ymax / 4)
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
					reverse_rotate_stack(&ahead, 'a');
			}
		}
		else if (aproc.temp <= dl.ymax / 4 && bproc.temp > dl.ymax / 4)
		{
			while (ahead != aproc.limit && bhead != bproc.limit)
			{
				rotate_stack(&ahead, 'a');
				reverse_rotate_stack(&bhead, 'b');
			}
			if (ahead == aproc.limit)
			{
				while (bhead != bproc.limit)
					reverse_rotate_stack(&bhead, 'b');
			}
			if (bhead == bproc.limit)
			{
				while (ahead != aproc.limit)
					rotate_stack(&ahead, 'a');
			}
		}
		else if (aproc.temp > dl.ymax / 4 && bproc.temp <= dl.ymax / 4)
		{
			while (ahead != aproc.limit && bhead != bproc.limit)
			{
				reverse_rotate_stack(&ahead, 'a');
				rotate_stack(&bhead, 'b');
			}
			if (ahead == aproc.limit)
			{
				while (bhead != bproc.limit)
					rotate_stack(&bhead, 'b');
			}
			if (bhead == bproc.limit)
			{
				while (ahead != aproc.limit)
					reverse_rotate_stack(&ahead, 'a');
			}
		}
//		stack_visualisation(&ahead, &bhead);
		if (bproc.limit->pos == dl.ymax)
			push_stack_a(&ahead, &bhead);
		while (bhead != NULL)
		{
			linked_list_circle(&ahead);
			if (ahead->pos == bhead->pos + 1)
				push_stack_a(&ahead, &bhead);
			else if (ahead->prev->pos > bhead->pos)
				reverse_rotate_stack(&ahead, 'a');
			else
				push_stack_a(&ahead, &bhead);
//			stack_visualisation(&ahead, &bhead);
		}
		find_mini_value(&ahead, &aproc);
		find_lst(&ahead, aproc.limit, &aproc);
		if (aproc.temp <= dl.ymax / 2)
		{
			while (ahead != aproc.limit)
				rotate_stack(&ahead, 'a');
		}
		else
		{
			while (ahead != aproc.limit)
				reverse_rotate_stack(&ahead, 'a');
		}
//		stack_visualisation(&ahead, &bhead);*/
	}
//	stack_visualisation(&ahead, &bhead);
	if (bhead == NULL && check_sort(&ahead) == 1 && ahead->pos == 1)
		exit(EXIT_SUCCESS);
	else
		return (0);
}
