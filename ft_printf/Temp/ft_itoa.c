/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:58:47 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/27 19:10:34 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//nbrlen voluntarily send the number of the last value inside the string

int	nbrlen(int n, int minus)
{
	int	len;

	if (n < 10)
		len = minus;
	else
	{
		len = 0;
		while (n >= 10)
		{
			n /= 10;
			len++;
		}
		len += minus;
	}
	return (len);
}

char	*memalloc(int n, int minus)
{
	int		len;
	char	*res;

	len = 0;
	if (n < 10)
	{
		res = ft_calloc((2 + minus), sizeof(char));
		if (res == NULL)
			return (NULL);
	}
	else
	{
		while (n >= 10)
		{
			n /= 10;
			len++;
		}
		res = ft_calloc((len + minus + 2), sizeof(char));
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

char	*fillerstr(int ires, int minus, char *res, int n)
{
	while (ires >= (0 + minus))
	{
		res[ires] = '0' + n % 10;
		n /= 10;
		ires--;
	}
	if (minus == 1)
		res[ires] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		minus;
	int		ires;

	minus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	res = memalloc(n, minus);
	if (res == NULL)
		return (NULL);
	ires = nbrlen(n, minus);
	return (fillerstr(ires, minus, res, n));
}

/*int	main()
{
	printf("%s\n", ft_itoa(100));
}*/
