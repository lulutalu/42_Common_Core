/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:41:22 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/21 15:52:05 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **head, char stack)
{
	t_node	*cur;
	t_node	*next;

	if ((*head)->prev != NULL)
		linked_list_linear(head);
	cur = *head;
	next = cur->next;
	cur->next = next->next;
	cur->prev = next;
	next->next = cur;
	next->prev = NULL;
	*head = next;
	if (stack != 's')
		ft_printf("s%c\n", stack);
}

void	rotate_stack(t_node **head, char stack)
{
	t_node	*scd;
	t_node	*cur;

	if ((*head)->prev != NULL)
		linked_list_linear(head);
	cur = *head;
	scd = (*head)->next;
	scd->prev = NULL;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = *head;
	(*head)->prev = cur;
	(*head)->next = NULL;
	*head = scd;
	if (stack != 'r')
		ft_printf("r%c\n", stack);
}

void	rotate_both(t_node **a, t_node **b)
{
	rotate_stack(a, 'r');
	rotate_stack(b, 'r');
	ft_printf("rr\n");
}

void	reverse_rotate_stack(t_node **head, char stack)
{
	t_node	*cur;

	if ((*head)->prev == NULL)
		linked_list_circle(head);
	*head = (*head)->prev;
	cur = *head;
	while (cur->next != *head)
		cur = cur->next;
	cur->next = NULL;
	(*head)->prev = NULL;
	if (stack != 'r')
		ft_printf("rr%c\n", stack);
}

void	reverse_rotate_both(t_node **a, t_node **b)
{
	reverse_rotate_stack(a, 'r');
	reverse_rotate_stack(b, 'r');
	ft_printf("rrr\n");
}
