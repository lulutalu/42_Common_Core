/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:09:19 by lduboulo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/23 21:00:06 by lduboulo         ###   ########.fr       */
=======
/*   Updated: 2021/11/26 01:59:32 by lduboulo         ###   ########.fr       */
>>>>>>> 923f750934fd3f3c7800cb6c7780d98a3a5df453
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
	char	*test = "Test";

	printf("Test %p", &test);
	//ft_printf("Ceci est un %s ", "test");
}
