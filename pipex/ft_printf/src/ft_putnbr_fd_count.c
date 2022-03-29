/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:14:36 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 01:09:35 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putnbr_fd_count(long n, int fd, int *count)
{
	char			cnbr;
	char			minus;
	unsigned int	nbr;

	minus = '-';
	if (n < 0)
	{
		write(fd, &minus, 1);
		nbr = n * -1;
		(*count)++;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd_count(nbr / 10, fd, count);
		ft_putnbr_fd_count(nbr % 10, fd, count);
	}
	if (nbr < 10)
	{
		cnbr = nbr + '0';
		write(fd, &cnbr, 1);
		(*count)++;
	}
}
