/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:58:47 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/29 19:18:08 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itoa base only works for base different than 10
// For base 10 use the regular Itoa

int	nbrlen(unsigned int n, unsigned int tbase)
{
	int	len;

	if (n < tbase)
		len = 1;
	else
	{
		len = 0;
		while (n >= tbase)
		{
			n /= tbase;
			len++;
		}
	}
	return (len);
}

void	*fillerstr(char **res, unsigned int n, int tbase)
{
	int		ires;

	ires = nbrlen(n, tbase);
	while (ires >= 0)
	{
		(*res)[ires] = '0' + n % tbase;
		n /= tbase;
		ires--;
	}
	return (NULL);
}

void	*check_base(char **res, char const *base)
{
	int	ires;
	int	ibase;

	ires = 0;
	while ((*res)[ires])
	{
		if ((*res)[ires] <= '9')
			ires++;
		else
		{
			ibase = ((*res)[ires] - '9') + 9;
			(*res)[ires] = base[ibase];
			ires++;
		}
	}
	return (NULL);
}

char	*ft_itoa_base(unsigned int n, char const *base)
{
	char	*res;
	int		tbase;

	tbase = ft_strlen(base);
	res = ft_calloc((nbrlen(n, tbase) + 2), sizeof(char));
	if (res == NULL)
		return (NULL);
	fillerstr(&res, n, tbase);
	check_base(&res, base);
	return (res);
}

/*int	main()
{
	printf("%s\n", ft_itoa_base(-5, "0123456789abcdef"));
}*/
