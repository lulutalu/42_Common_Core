/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:41:22 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/08 14:47:20 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **head)
{
	t_node	*first;
	t_node	*second;

	printf("%d\n", (*head)->next->next->value);
	first = *head;
	second = (*head)->next;
	second->next = first;
	second->prev = NULL;
	(*head) = second;
	first->prev = (*head);
	first->next = (*head)->next->next;
	printf("%d %d\n", first->value, second->value);
	printf("%d %d %d\n", (*head)->value, (*head)->next->value, (*head)->next->next->value);
}
