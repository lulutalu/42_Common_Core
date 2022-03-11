/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_manipulation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/11 21:45:52 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add(t_node **head, int value)
{
	t_node	*new;
	t_node	*last;

	new = ft_calloc(1, sizeof(t_node));
	ft_mem_alloc_check(new);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

t_node	*find_last(t_node **head)
{
	t_node	*cur;

	cur = *head;
	while (cur->next != NULL)
		cur = cur->next;
	return (cur);
}

void	linked_list_circle(t_node **head)
{
	t_node	*cur;

	if ((*head)->prev == NULL)
	{
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = *head;
		(*head)->prev = cur;
	}
}

void	linked_list_linear(t_node **head)
{
	t_node	*cur;

	if ((*head)->prev != NULL)
	{
		cur = *head;
		while (cur->next != *head)
			cur = cur->next;
		cur->next = NULL;
		(*head)->prev = NULL;
	}
}
