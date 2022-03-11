/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:32:38 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/12 00:04:06 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack_b(t_node **a, t_node **b)
{
	t_node	*cur;

	if (*a == NULL)
		return (0);
	if (*b != NULL)
		linked_list_linear(b);
	linked_list_linear(a);
	cur = *a;
	if ((*a)->next != NULL)
	{
		*a = (*a)->next;
		(*a)->prev = NULL;
	}
	else
		*a = NULL;
	push_stack_b_2(b, &cur);
	ft_printf("pb\n");
	return (1);
}

void	push_stack_b_2(t_node **b, t_node **cur)
{
	if (*b != NULL)
	{
		(*cur)->next = *b;
		(*b)->prev = *cur;
		*b = *cur;
	}
	else
	{
		*b = *cur;
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
}

int	push_stack_a(t_node **a, t_node **b)
{
	t_node	*cur;

	if (*b == NULL)
		return (0);
	if (*a != NULL)
		linked_list_linear(a);
	linked_list_linear(b);
	cur = *b;
	if ((*b)->next != NULL)
	{
		*b = (*b)->next;
		(*b)->prev = NULL;
	}
	else
		*b = NULL;
	push_stack_a_2(a, &cur);
	ft_printf("pa\n");
	return (1);
}

void	push_stack_a_2(t_node **a, t_node **cur)
{
	if (*a == NULL)
	{
		(*cur)->next = NULL;
		(*cur)->prev = NULL;
		*a = *cur;
	}
	else
	{
		(*cur)->next = *a;
		(*a)->prev = *cur;
		*a = *cur;
	}
}
