/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:38:46 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/28 15:11:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double	check_of_args(int argc, char **argv)
{
	t_arg		args;

	args.iarg = 1;
	args.narg = 0;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else
	{
		if (argc == 2)
			return (check_of_arg_2(&args, argv));
		else
			return (check_of_arg_n(&args, argc, argv));
	}
}

t_double	check_of_arg_2(t_arg *args, char **argv)
{
	args->arg = argv[1];
	args->i = 0;
	while (args->i < (int)ft_strlen(args->arg))
	{
		if (args->arg[args->i] >= 48 && args->arg[args->i] <= 57)
		{
			args->narg++;
			while (args->arg[args->i] && (args->arg[args->i] >= 48 && \
						args->arg[args->i] <= 57))
				args->i++;
		}
		if (args->arg[args->i] == 32 && args->arg[args->i - 1] == 32)
			error_exit(SYN);
		if (!(args->arg[args->i] >= 48 && args->arg[args->i] <= 57) && \
				args->arg[args->i] != 32 && args->arg[args->i] != '\0' \
				&& args->arg[args->i] != 45)
			error_exit(NOT_DIGIT);
		args->i++;
	}
	if (args->narg < 2)
		error_exit(NENB);
	return (double_arg_2(argv));
}

t_double	check_of_arg_n(t_arg *args, int argc, char **argv)
{
	while (args->iarg < argc)
	{
		args->arg = argv[args->iarg];
		args->i = 0;
		while (args->arg[args->i])
		{
			if (ft_isdigit(args->arg[args->i]) == 0 && args->arg[args->i] != 45)
				error_exit(NOT_DIGIT);
			args->i++;
		}
		args->iarg++;
	}
	return (double_arg_n(argc, argv));
}

t_double	double_arg_2(char **argv)
{
	t_double	dl;

	dl.split = ft_split(argv[1], ' ');
	dl.ymax = 0;
	while (dl.split[dl.ymax])
		dl.ymax++;
	dl.tab = ft_calloc(dl.ymax + 1, sizeof(int));
	ft_mem_alloc_check(dl.tab);
	dl.y = 0;
	while (dl.y < dl.ymax)
	{
		limits_check(ft_atol(dl.split[dl.y]));
		dl.tab[dl.y] = ft_atoi(dl.split[dl.y]);
		free(dl.split[dl.y]);
		dl.y++;
	}
	free(dl.split);
	double_arg_tab_check(&dl);
	return (dl);
}

void	double_arg_tab_check(t_double *dl)
{
	dl->y = 0;
	while (dl->y < dl->ymax)
	{
		dl->ncheck = 0;
		dl->cp = 0;
		while (dl->cp < dl->ymax)
		{
			if (dl->tab[dl->cp] == dl->tab[dl->y])
				dl->ncheck++;
			dl->cp++;
		}
		if (dl->ncheck > 1)
			error_exit(DOUBLE);
		dl->y++;
	}
}
