/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:09:19 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/26 14:28:20 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(long n, int fd)
{
	char			cnbr;
	unsigned int	nbr;
	char			minus;

	minus = '-';
	if (n < 0)
	{
		write(fd, &minus, 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_puthex_fd(nbr / 16, fd);
		ft_puthex_fd(nbr % 16, fd);
	}
	if (nbr < 10)
	{
		cnbr = '0' + nbr;
		write(fd, &cnbr, 1);
	}
}

int	ft_printf(const char *input, ...)
{
	int				i;
	va_list 		arg;
	char			*str;
	unsigned int	res;

	va_start(arg, input);
	i = 0;
	while (input[i] && input[i] != '%')
		i++;
	if (input[i++] == '%')
	{
		str = ft_substr(input, 0, i - 1);
		ft_putstr_fd(str, 1);
		free(str);
		if (input[i] == 'c')
		{
			ft_putchar_fd(va_arg(arg, int), 1);
		}
		if (input[i] == 's')
		{
			str = ft_strdup(va_arg(arg, char *));
			ft_putstr_fd(str, 1);
			free(str);
		}
		if (input[i] == 'p')
		{
			/*str = ft_strdup(&(va_arg(arg, char **)));
			ft_putstr_fd(&str, 1);
			free(str);*/
			return (1);
		}
		if (input[i] == 'd')
		{
			ft_putnbr_fd(va_arg(arg, int), 1);
			return (1);
		}
		if (input[i] == 'i')
		{
			ft_putnbr_fd(va_arg(arg, int), 1);
			return (1);
		}
		if (input[i] == 'u')
		{
			res = va_arg(arg, int);
			ft_putnbr_fd(res, 1);
			return (1);
		}
		if (input[i] == 'x')
		{
			ft_puthex_fd(va_arg(arg, int), 1);
			return (1);
		}
		if (input[i] == 'X')
			return (1);
		if (input[i] == '%')
			return (1);
		if (input[i + 1] != '\0')
		{
			str = ft_substr(input, i + 1, ft_strlen(str) - (i + 1));
			ft_putstr_fd(str, 1);
			free(str);
			return (1);
		}
		else
			return (1);
	}
	if (input[i + 1] != '\0')
	{
		str = ft_substr(input, i + 1, ft_strlen(str) - (i + 1));
		ft_putstr_fd(str, 1);
		free(str);
		return (1);
	}
	else
		return (1);
	return (0);
}

int	main()
{
	//char	*test = "Test";
	int	i = 800;

	printf("Fonction C = %x\n", i);
	ft_printf("Fonction mano = %x\n", i);
}
