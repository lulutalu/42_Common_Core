/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:06:51 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/28 14:43:24 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_3_sort(t_node **head, int pmax)
{
	while (check_sort(head) == 0)
	{
		if ((*head)->pos == pmax)
			rotate_stack(head, 'a');
		else if ((*head)->pos == pmax - 1 && (*head)->next->pos == pmax - 2)
			swap_stack(head, 'a');
		else if ((*head)->pos == pmax - 2)
		{
			swap_stack(head, 'a');
			rotate_stack(head, 'a');
		}
		else if ((*head)->pos == pmax - 1 && (*head)->next->pos == pmax)
			reverse_rotate_stack(head, 'a');
	}
}

void	n_5_sort(t_node **a, t_node **b, int ymax)
{
	int		comp;

	linked_list_circle(a);
	comp = 1;
	while (comp < 3)
	{
		while ((*a)->pos != comp)
		{
			if ((*a)->next->pos != comp && (*a)->next->next->pos != comp)
				reverse_rotate_stack(a, 'a');
			else
				rotate_stack(a, 'a');
		}
		push_stack_b(a, b);
		comp++;
	}
	n_3_sort(a, ymax);
	while (*b != NULL)
		push_stack_a(a, b);
}

void	n_sort(t_node **ahead, t_node **bhead, int nmax)
{
	t_chunk	chunk;

	chunk_size_selection(nmax, &chunk);
	chunk.n = 1;
	chunk.nnode = nmax;
	while ((*ahead) != NULL)
	{
		chunk.i = 1;
		if (chunk.n == 1)
			push_to_b_1st_chunk(ahead, bhead, &chunk);
		else if (chunk.nnode >= chunk.size + chunk.size / 8)
			push_to_b_n_chunk(ahead, bhead, &chunk);
		else
			push_to_b_last(ahead, bhead, &chunk);
		chunk.n++;
	}
	sort_push(ahead, bhead, &chunk, nmax);
}

void	find_biggest_value(t_node **head, t_info *proc)
{
	t_node	*cur;

	proc->aim = *head;
	proc->i = 1;
	proc->temp = 1;
	cur = *head;
	while (cur != NULL)
	{
		if (cur->pos > proc->aim->pos)
		{
			proc->aim = cur;
			proc->temp = proc->i;
		}
		proc->i++;
		cur = cur->next;
	}
	proc->limit = proc->aim;
}

void	find_next_big(t_node **head, t_info *proc)
{
	t_node	*cur;

	proc->i = 1;
	proc->temp = 1;
	linked_list_circle(head);
	proc->curaim = proc->aim->next;
	linked_list_linear(head);
	cur = *head;
	while (cur != NULL)
	{
		if (cur->pos > proc->curaim->pos && cur->pos < proc->aim->pos)
		{
			proc->curaim = cur;
			proc->temp = proc->i;
		}
		cur = cur->next;
		proc->i++;
	}
	linked_list_circle(head);
	if (proc->curaim == proc->aim->next)
		proc->temp = 1;
	linked_list_linear(head);
}
