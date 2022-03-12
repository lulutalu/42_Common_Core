/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:06:51 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/12 17:38:41 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_3_sort(t_node **head, int pmax)
{
	t_node	*cur;

	while (check_sort(head) == 0)
	{
		linked_list_circle(head);
		cur = *head;
		if (cur->pos == pmax)
			rotate_stack(head, 'a');
		else if (cur->pos == pmax - 1 && cur->next->pos == pmax - 2)
			swap_stack(head, 'a');
		else if (cur->prev->pos == pmax - 2)
			reverse_rotate_stack(head, 'a');
		else if (cur->pos == pmax - 2 && cur->prev->pos == pmax - 1)
		{
			reverse_rotate_stack(head, 'a');
			swap_stack(head, 'a');
		}
	}
}

void	n_5_sort(t_node **a, t_node **b, int ymax)
{
	t_node	*acur;
	t_node	*bcur;
	int		comp;

	linked_list_circle(a);
	acur = *a;
	if (acur->prev->pos == 1)
		reverse_rotate_stack(a, 'a');
	comp = 1;
	while (comp < 3)
	{
		acur = *a;
		bcur = *b;
		while (acur->pos != comp)
		{
			rotate_stack(a, 'a');
			acur = *a;
		}
		push_stack_b(a, b);
		comp++;
	}
	n_3_sort(a, ymax);
	while (*b != NULL)
		push_stack_a(a, b);
}
