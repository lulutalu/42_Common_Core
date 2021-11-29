/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:09:19 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/29 21:41:14 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			ft_putstr_fd(ft_itoa_base(va_arg(arg, int), "0123456789abcdef"), 1);
			return (1);
		}
		if (input[i] == 'X')
		{
			ft_putstr_fd(ft_itoa_base(va_arg(arg, int), "0123456789ABCDEF"), 1);
			return (1);
		}
		if (input[i] == '%')
		{
			ft_putchar_fd('%', 1);
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
	int	i = 985743;

	printf("Fonction C = %%\n");
	ft_printf("Fonction mano = %d ouais \n", i);
}
