/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_desc_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:14:05 by lduboulo          #+#    #+#             */
/*   Updated: 2022/02/22 13:50:48 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_desc_opening(t_file *file)
{
	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
	{
		ft_putendl_fd(FD_OP_ERROR, 2);
		exit(EXIT_FAILURE);
	}
}

void	file_desc_closing(t_file *file)
{
	if (close(file->fd) != 0)
	{
		ft_putendl_fd(FD_CLS_ERROR, 2);
		exit(EXIT_FAILURE);
	}
}
