/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:32:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/08 19:15:36 by lduboulo         ###   ########.fr       */
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
	int		temp;

	cur = *head;
	while (cur->next != NULL)
	{
		temp = cur->value;
		if (temp < cur->next->value)
			cur = cur->next;
		else
			return (0);
	}
	if (cur->next == NULL)
		return (1);
	else
		return (0);
}

void	stack_visualisation(t_node **head)
{
	t_node	*cur;

	printf("Stack a ----------------- Stack b\n");
	printf("---------------------------------\n");
	cur = *head;
	while (cur != NULL)
	{
		printf("    %d\n", cur->value);
		cur = cur->next;
	}
	printf("---------------------------------\n");
}
