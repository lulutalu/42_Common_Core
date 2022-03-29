/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:04:13 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 01:10:57 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	variable_counter(t_printf *ptr, const char *input)
{	
	while (input[ptr->i])
	{
		if (input[ptr->i] == '%')
		{
			ptr->iparam = 0;
			while (ptr->param[ptr->iparam])
			{
				if (input[ptr->i + 1] == ptr->param[ptr->iparam])
				{
					ptr->nbvar++;
					ptr->i++;
					break ;
				}
				ptr->iparam++;
			}
		}
		ptr->i++;
	}
}
