/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:06:51 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/11 17:03:06 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_3_sort(t_node **head)
{
	t_node	*cur;

	while (check_sort(head) == 0)
	{
		linked_list_circle(head);
		cur = *head;
		if (cur->pos == 3)
			rotate_stack(head, 'a');
		else if (cur->pos == 2 && cur->next->pos == 1)
			swap_stack(head, 'a');
		else if (cur->prev->pos == 1)
			reverse_rotate_stack(head, 'a');
		else if (cur->pos == 1 && cur->prev->pos == 2)
		{
			reverse_rotate_stack(head, 'a');
			swap_stack(head, 'a');
		}
	}
}
