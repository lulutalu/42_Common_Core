/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:39:30 by lduboulo          #+#    #+#             */
/*   Updated: 2021/12/06 18:40:40 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str1;
	char	*str2;
	char	doublon[256];
	int		i1 = 0;
	int		i2 = 0;
	int		id = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		str1 = argv[1];
		str2 = argv[2];
		while (str1[i1])
		{
			i2 = 0;
			while (str2[i2])
			{
				if (str2[i2] == str1[i1])
			}
		}
	}
}
