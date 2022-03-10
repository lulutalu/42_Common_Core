/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:56:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/08 19:40:09 by lduboulo         ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

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
 * Function for exit and error
*/

int			error_exit(char *error);

/*
 * Linked list manipulation
*/

void		lst_add(t_node **head, int value);
t_node		*find_last(t_node **head);

/*
 * Sorting Algorithm Functions
*/

int			check_sort(t_node **head);
void		stack_visualisation(t_node **head);
void		swap_stack(t_node **head, char stack);
void		rotate_stack(t_node **head, char stack);
void		reverse_rotate_stack(t_node **head, char stack);

#endif
