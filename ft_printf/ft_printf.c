/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:09:19 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/23 21:00:06 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list arg;
	char	*str;

	va_start(arg, input);
	i = 0;
	while (input[i] && input[i] != '%')
		i++;
	if (input[i++] == '%')
	{
		if (input[i] == 'c')
		{
			str = ft_substr(input, 0, i - 1);
			ft_putstr_fd(str, 1);
			free(str);
			ft_putchar_fd(va_arg(arg, int), 1);
			str = ft_substr(input, i + 1, ft_strlen(str) - (i + 1));
			ft_putstr_fd(str, 1);
			free(str);
			return (1);
		}
		if (input[i] == 's')
		{
			str = ft_substr(input, 0, i - 1);
			ft_putstr_fd(str, 1);
			free(str);
			str = ft_strdup(va_arg(arg, char *));
			ft_putstr_fd(str, 1);
			free(str);
			str = ft_substr(input, i + 1, ft_strlen(str) - (i + 1));
			ft_putstr_fd(str, 1);
			free(str);
			return (1);
		}
		if (input[i] == 'p')
			return (1);
		if (input[i] == 'd')
			return (1);
		if (input[i] == 'i')
			return (1);
		if (input[i] == 'u')
			return (1);
		if (input[i] == 'x')
			return (1);
		if (input[i] == 'X')
			return (1);
		if (input[i] == '%')
			return (1);
	}
	else
	{
		ft_putstr_fd((char *)input, 1);
		return (1);
	}
	return (0);
}
