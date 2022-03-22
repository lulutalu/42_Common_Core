/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/22 16:51:08 by lduboulo         ###   ########.fr       */
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
	int			nchunk;
	int			nnode;
	t_proc		bproc;
//	t_proc		aproc;

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
		chunk = 60;
		nchunk = 1;
		nnode = dl.ymax;
		while (ahead != NULL)
		{
			i = 1;
			if (nchunk == 1)
			{
				while (i <= chunk && ahead != NULL)
				{
					while (ahead->pos > nchunk * chunk)
						rotate_stack(&ahead, 'a');
					push_stack_b(&ahead, &bhead);
					i++;
				}
			}
			else
			{
				while (i <= chunk && ahead != NULL)
				{
					while (ahead->pos > nchunk * chunk || ahead->pos <= (nchunk - 1) * chunk)
					{
						if (ahead->next != NULL)
							rotate_stack(&ahead, 'a');
					}
					if (ahead->pos > nchunk * chunk - chunk / 2)
					{
						push_stack_b(&ahead, &bhead);
						rotate_stack(&bhead, 'b');
					}
					else
						push_stack_b(&ahead, &bhead);
					i++;
				}
			}
			nchunk++;
		}
		find_biggest_value(&bhead, &bproc);
		bproc.curaim = bproc.aim;
		while (bhead != NULL)
		{
			if (bproc.temp <= nnode / 2)
			{
				while (bhead != bproc.curaim)
					rotate_stack(&bhead, 'b');
			}
			else if (bproc.temp > nnode / 2)
			{
				while (bhead != bproc.curaim)
					reverse_rotate_stack(&bhead, 'b');
			}
			bproc.aim = bproc.curaim;
			find_next_big(&bhead, &bproc);
			push_stack_a(&ahead, &bhead);
			nnode--;
		}
/*		find_biggest_value(&bhead, &bproc);
		test = 2;
		while (test-- > 0)
		{
			while (invert_check_sort(&bhead) == 0)
			{
				linked_list_linear(&bhead);
				find_next_big(&bhead, &bproc);
				if (bproc.temp <= chunk / 2)
				{
					while (bhead != bproc.curaim)
						rotate_stack(&bhead, 'b');
				}
				else if (bproc.temp > chunk / 2)
				{
					while (bhead != bproc.curaim)
						reverse_rotate_stack(&bhead, 'b');
				}
				if (bhead == bproc.curaim)
				{
					find_lst(&bhead, bproc.aim, &bproc);
					if (bproc.temp <= chunk / 2)
					{
						while (bhead->next != bproc.aim)
						{
							swap_stack(&bhead, 'b');
							rotate_stack(&bhead, 'b');
						}
						swap_stack(&bhead, 'b');
					}
					else if (bproc.temp > chunk / 2)
					{
						linked_list_circle(&bhead);
						while (bhead->prev != bproc.aim)
						{
							reverse_rotate_stack(&bhead, 'b');
							swap_stack(&bhead, 'b');
							linked_list_circle(&bhead);
						}
						reverse_rotate_stack(&bhead, 'b');
					}
				}
				bproc.aim = bproc.curaim;
			}
			find_lst(&bhead, bproc.limit, &bproc);
			if (bproc.temp <= chunk / 2)
			{
				while (bhead != bproc.limit)
					rotate_stack(&bhead, 'b');
			}
			else if (bproc.temp > chunk / 2)
			{
				while (bhead != bproc.limit)
					reverse_rotate_stack(&bhead, 'b');
			}
			i = 0;
			if (nchunk == 2)
			{
				while (i++ < chunk && bhead != NULL)
					push_stack_a(&ahead, &bhead);
			}
			else
			{
				if (nchunk == 3)
					i = 1;
				else
					i = 0;
				while (i < chunk)
				{
					find_next_mini(&ahead, &aproc);
					aproc.aim = aproc.curaim;
					i++;
				}
				find_lst(&ahead, aproc.curaim, &aproc);
				linked_list_circle(&ahead);
				if (aproc.temp <= (dl.ymax - chunk) / 2)
				{
					while (ahead->prev != aproc.curaim)
					{
						rotate_stack(&ahead, 'a');
						linked_list_circle(&ahead);
					}
				}
				else if (aproc.temp > (dl.ymax - chunk) / 2)
				{
					while (ahead->prev != aproc.curaim)
					{
						reverse_rotate_stack(&ahead, 'a');
						linked_list_circle(&ahead);
					}
				}
				while (bhead != NULL)
					push_stack_a(&ahead, &bhead);
			}
			if (test > 0)
			{
				i = 0;
				while (i++ < chunk)
					reverse_rotate_stack(&ahead, 'a');
				i = 0;
				while (i < chunk && ahead != NULL)
				{
					while (ahead->pos > nchunk * chunk || ahead->pos <= (nchunk - 1) * chunk)
						reverse_rotate_stack(&ahead, 'a');
					push_stack_b(&ahead, &bhead);
					i++;
				}
				nchunk++;
				find_biggest_value(&bhead, &bproc);
			}
		}
		find_lst(&ahead, aproc.limit, &aproc);
		if (aproc.temp <= dl.ymax / 2)
		{
			while (ahead != aproc.limit)
				rotate_stack(&ahead, 'a');
		}
		else if (aproc.temp > dl.ymax / 2)
		{
			while (ahead != aproc.limit)
				reverse_rotate_stack(&ahead, 'a');
		}
		/////////////////////////////////////////////////////////////
//		stack_visualisation(&ahead, &bhead);*/
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
	if (bhead == NULL && ahead->pos == 1)
//	if (ahead == NULL && invert_check_sort(&bhead) == 1)
		exit(EXIT_SUCCESS);
	else
		return (0);
}
