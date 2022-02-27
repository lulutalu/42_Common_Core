/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 23:02:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*arg;
	int		iarg;
	int		i;

	iarg = 1;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else
	{
		while (iarg < argc)
		{
			arg = argv[iarg++];
			i = 0;
			while (arg[i])
			{
				if (ft_isdigit(arg[i++]) == 0)
				{
					ft_putendl_fd(NOT_DIGIT, 2);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
}
