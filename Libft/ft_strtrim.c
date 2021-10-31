/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:49:10 by lduboulo          #+#    #+#             */
/*   Updated: 2021/10/26 13:54:33 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_var
{
	int	i;
	int	iset;
	int	start;
	int	len;
}				t_var;

void	setcheck1(char const *s1, char const *set, t_var *var)
{
	while (s1[var->i] != '\0' && !(var->i > (var->start + 1)))
	{
		var->iset = 0;
		while (set[var->iset] != '\0')
		{
			if ((int)s1[var->i] == (int)set[var->iset])
				var->start = var->i;
			var->iset++;
		}
		var->i++;
	}
}

void	setcheck2(char const *s1, char const *set, t_var *var)
{
	while (var->i > var->start && !(var->i < (var->len - 1)))
	{
		var->iset = 0;
		while (set[var->iset] != '\0')
		{
			if ((int)s1[var->i] == (int)set[var->iset])
				var->len = var->i;
			var->iset++;
		}
		var->i--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	t_var	var;

	if (set == NULL || s1 == NULL)
		return ((char *)s1);
	var.i = 0;
	var.start = 0;
	setcheck1(s1, set, &var);
	if (var.start > 0)
		var.start += 1;
	var.i = ft_strlen(s1);
	var.len = var.i;
	setcheck2(s1, set, &var);
	return (ft_substr(s1, var.start, (var.len - var.start)));
}
