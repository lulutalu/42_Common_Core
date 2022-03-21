/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:52:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/21 17:47:59 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_next_mini(t_node **head, t_proc *proc)
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
		if (cur->pos > proc->aim->pos && cur->pos < proc->curaim->pos)
		{
			proc->curaim = cur;
			proc->temp = proc->i;
		}
		proc->i++;
		cur = cur->next;
	}
	linked_list_circle(head);
	if (proc->curaim == proc->aim->next)
		find_lst(head, proc->curaim, proc);
	linked_list_linear(head);
	check_next_mini(head, proc);
}

void	find_lst(t_node **head, t_node *needle, t_proc *proc)
{
	t_node	*cur;

	cur = *head;
	proc->i = 1;
	while (cur != needle)
	{
		cur = cur->next;
		proc->i++;
	}
	proc->temp = proc->i;
}

void	check_next_big(t_node **head, t_proc *proc)
{
	if (proc->curaim == proc->aim->next)
	{
		proc->aim = proc->curaim;
		find_next_big(head, proc);
	}
}

void	check_next_mini(t_node **head, t_proc *proc)
{
	if (proc->curaim == proc->aim->next)
	{
		proc->aim = proc->curaim;
		find_next_mini(head, proc);
	}
}
