/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:32:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/15 17:30:24 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	check_sort(t_node **head)
{
	t_proc	check;
	t_node	*cur;

	find_mini_value(head, &check);
	linked_list_circle(head);
	cur = *head;
	while (cur != check.limit)
		cur = cur->next;
	while (cur->next != check.limit)
	{
		if (cur->value < cur->next->value)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}

int	invert_check_sort(t_node **head)
{
	t_node	*cur;
	t_proc	check;

	find_biggest_value(head, &check);
	linked_list_circle(head);
	cur = *head;
	while (cur != check.limit)
		cur = cur->next;
	while (cur->next != check.limit)
	{
		if (cur->value > cur->next->value)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}

void	stack_visualisation(t_node **a, t_node **b)
{
	t_node	*acur;
	t_node	*bcur;

	if (*a != NULL)
	{
		if ((*a)->prev != NULL)
			linked_list_linear(a);
		acur = *a;
	}
	else
		acur = NULL;
	if (*b != NULL)
	{
		if ((*b)->prev != NULL)
			linked_list_linear(b);
		bcur = *b;
	}
	else
		bcur = NULL;
	printf("Stack a ----------------- Stack b\n");
	printf("---------------------------------\n");
	while (acur != NULL || bcur != NULL)
	{
		if (acur != NULL)
		{
			printf("%d.   %d", acur->pos, acur->value);
			acur = acur->next;
		}
		if (bcur != NULL)
		{
			printf("                 %d.   %d", bcur->pos, bcur->value);
			bcur = bcur->next;
		}
		printf("\n");
	}
	printf("---------------------------------\n");
}

t_node	*mini_value(t_node **head)
{
	t_node	*cur;
	t_node	*find;
	t_node	*mini;

	cur = *head;
	find = *head;
	while (cur != NULL)
	{
		if (cur->value < find->value)
			find = cur;
		cur = cur->next;
	}
	mini = find;
	mini->pos = 1;
	return (mini);
}

void	value_listing(t_node **head, int narg)
{
	t_node	*cur;
	t_node	*find;
	t_node	*mini;
	int		i;

	i = 2;
	mini = mini_value(head);
	while (i < narg)
	{
		cur = *head;
		while (cur->pos > 0)
			cur = cur->next;
		find = cur;
		cur = *head;
		while (cur != NULL)
		{
			if (cur->value < find->value && cur->value > mini->value)
				find = cur;
			cur = cur->next;
		}
		mini = find;
		mini->pos = i++;
	}
}
