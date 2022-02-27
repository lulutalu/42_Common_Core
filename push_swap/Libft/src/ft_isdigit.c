/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:38:57 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/27 22:45:12 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*int main()
{
	char	c;

	c = 't';
	printf("Resultat fonction C %i\n", isdigit(c));
	printf("Resultat fonction mano %i\n", ft_isdigit(c));
}*/
