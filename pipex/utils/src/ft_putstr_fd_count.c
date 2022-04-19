/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:39:00 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/04 11:21:08 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_putstr_fd_count(char *s, int fd)
{
	int	idx;

	idx = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[idx] != '\0')
		{
			write(fd, s + idx, 1);
			idx++;
		}
		return (idx);
	}
}
