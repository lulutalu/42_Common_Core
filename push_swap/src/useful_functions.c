/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:32:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/28 14:43:48 by lduboulo         ###   ########.fr       */
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
	t_node	*cur;

	cur = *head;
	while (cur->next != NULL)
	{
		if (cur->value < cur->next->value)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
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
