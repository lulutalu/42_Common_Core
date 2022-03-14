/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:52:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/14 23:32:23 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_next_mini(t_node **head, t_proc *proc)
{
	t_node	*cur;

	proc->i = 1;
	proc->temp = 1;
	cur = *head;
	while (cur != NULL)
	{
		if (cur->pos > proc->aim->pos && cur->pos < proc->curaim->pos)
		{
			proc->curaim = cur;
			proc->temp = proc->i;
		}
		proc->i++;
		cur = cur->next;
	}
}

void	find_lst(t_node **head, t_node *needle, t_proc *proc)
{
	t_node	*cur;

	cur = *head;
	proc->i = 0;
	while (cur != needle)
	{
		cur = cur->next;
		proc->i++;
	}
}
