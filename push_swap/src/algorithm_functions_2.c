/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_functions_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:10:48 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/28 14:42:44 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_size_selection(int nmax, t_chunk *chunk)
{
	if (nmax <= 50)
		chunk->size = 5;
	else if (nmax <= 100)
		chunk->size = 16;
	else
		chunk->size = nmax / 10;
}

void	push_to_b_1st_chunk(t_node **ahead, t_node **bhead, t_chunk *chunk)
{
	while (chunk->i <= chunk->size && (*ahead) != NULL)
	{
		while ((*ahead)->pos > chunk->n * chunk->size)
			rotate_stack(ahead, 'a');
		if ((*ahead)->pos > chunk->n * chunk->size - chunk->size / 2)
		{
			push_stack_b(ahead, bhead);
			if ((*bhead)->next != NULL)
				rotate_stack(bhead, 'b');
		}
		else
			push_stack_b(ahead, bhead);
		chunk->nnode--;
		chunk->i++;
	}
}

void	push_to_b_n_chunk(t_node **ahead, t_node **bhead, t_chunk *chunk)
{
	while (chunk->i <= chunk->size && (*ahead) != NULL)
	{
		while ((*ahead)->pos > chunk->n * chunk->size || \
				(*ahead)->pos <= (chunk->n - 1) * chunk->size)
		{
			if ((*ahead)->next != NULL)
				rotate_stack(ahead, 'a');
		}
		if ((*ahead)->pos > chunk->n * chunk->size - chunk->size / 2)
		{
			push_stack_b(ahead, bhead);
			rotate_stack(bhead, 'b');
		}
		else
			push_stack_b(ahead, bhead);
		chunk->nnode--;
		chunk->i++;
	}
}

void	push_to_b_last(t_node **ahead, t_node **bhead, t_chunk *chunk)
{
	while ((*ahead) != NULL)
	{
		if ((*ahead)->pos > chunk->n * chunk->size - chunk->size / 2)
		{
			push_stack_b(ahead, bhead);
			rotate_stack(bhead, 'b');
		}
		else
			push_stack_b(ahead, bhead);
	}
}

void	sort_push(t_node **ahead, t_node **bhead, t_chunk *chunk, int nmax)
{
	t_info	b;

	find_biggest_value(bhead, &b);
	b.curaim = b.aim;
	chunk->nnode = nmax;
	while ((*bhead) != NULL)
	{
		if (b.temp <= chunk->nnode / 2)
		{
			while ((*bhead) != b.curaim)
				rotate_stack(bhead, 'b');
		}
		else if (b.temp > chunk->nnode / 2)
		{
			while ((*bhead) != b.curaim)
				reverse_rotate_stack(bhead, 'b');
		}
		b.aim = b.curaim;
		find_next_big(bhead, &b);
		push_stack_a(ahead, bhead);
		chunk->nnode--;
	}
}
