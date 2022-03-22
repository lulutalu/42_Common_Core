/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:56:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/22 16:51:09 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 * Default Library
*/

# include "push_swap.h"
# include "./../Libft/src/libft.h"

/*
 * Authorized Function Library
*/

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

/*
 * Define of Macro
*/

# define NOT_DIGIT "\e[1;31mError, something else than digits in arg\e[0m"
# define NENB "\e[1;31mError, not enough numbers to form a stack\e[0m"
# define SYN "\e[1;31mError, syntax of arg not correct\e[0m"
# define DOUBLE "\e[1;31mError, repetion of the same integer\e[0m"

/*
 * Structures
*/

typedef struct s_arg
{
	int		iarg;
	int		i;
	char	*arg;
	int		narg;
}			t_arg;

typedef struct s_double
{
	char	**split;
	int		*tab;
	int		ymax;
	int		y;
	int		ncheck;
	int		cp;
}			t_double;

typedef struct s_node
{
	int				value;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_proc
{
	int		temp;
	int		i;
	t_node	*aim;
	t_node	*curaim;
	t_node	*limit;
}				t_proc;

/*
 * Functions for Arg checking
*/

t_double	check_of_args(int argc, char **argv);
t_double	check_of_arg_2(t_arg *args, char **argv);
t_double	check_of_arg_n(t_arg *args, int argc, char **argv);
t_double	double_arg_2(char **argv);
t_double	double_arg_n(int argc, char **argv);
void		double_arg_tab_check(t_double *dl);

/*
 * QOL Functions
*/

int			error_exit(char *error);
void		stack_visualisation(t_node **a, t_node **b);
t_node		*mini_value(t_node **head);
void		value_listing(t_node **head, int argc);
int			invert_check_sort(t_node **head);

/*
 * Linked list manipulation
*/

void		lst_add(t_node **head, int value);
void		linked_list_circle(t_node **head);
void		linked_list_linear(t_node **head);
void		find_lst(t_node **head, t_node *needle, t_proc *proc);

/*
 * Sorting Algorithm Extra Functions
*/

int			check_sort(t_node **head);
////////////////////////////////////////////////////////////
void		swap_stack(t_node **head, char stack);
void		swap_both(t_node **a, t_node **b);
///////////////////////////////////////////////////////////
void		rotate_stack(t_node **head, char stack);
void		rotate_both(t_node **a, t_node **b);
//////////////////////////////////////////////////////////
void		reverse_rotate_stack(t_node **head, char stack);
void		reverse_rotate_both(t_node **a, t_node **b);
/////////////////////////////////////////////////////////
int			push_stack_a(t_node **a, t_node **b);
void		push_stack_a_2(t_node **a, t_node **cur);
/////////////////////////////////////////////////////////
int			push_stack_b(t_node **a, t_node **b);
void		push_stack_b_2(t_node **b, t_node **cur);

/*
 * Sorting Algorithm Functions
*/

void		n_3_sort(t_node **head, int pmax);
void		n_5_sort(t_node **a, t_node **b, int ymax);
void		find_biggest_value(t_node **head, t_proc *proc);
void		find_next_big(t_node **head, t_proc *proc);
void		check_next_big(t_node **head, t_proc *proc);
void		find_mini_value(t_node **head, t_proc *proc);
void		find_next_mini(t_node **head, t_proc *proc);
void		check_next_mini(t_node **head, t_proc *proc);

#endif
