/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:30:04 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/01 16:32:57 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		iarg;
	int		i;
	char	*arg;
	int		narg;

	iarg = 1;
	narg = 0;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	else
	{
		if (argc == 2)
		{
			arg = argv[1];
			i = 0;
			while (i < (int)ft_strlen(arg))
			{
				if (arg[i] >= 48 && arg[i] <= 57)
				{
					narg++;
					while (arg[i] && (arg[i] >= 48 && arg[i] <= 57))
						i++;
				}
				if (arg[i] == 32 && arg[i - 1] == 32)
				{
					ft_putendl_fd(SYN, 2);
					exit(EXIT_FAILURE);
				}
				i++;
			}
			printf("Narg %d\n", narg);
			if (narg < 2)
			{
				ft_putendl_fd(NENB, 2);
				exit(EXIT_FAILURE);
			}
		}
	}
}
