/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:02:29 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/08 16:13:50 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	extension_checker(char *filename)
{
	int		ifile;
	int		iext;
	char	*ext;

	iext = 0;
	ext = ft_strdup(".fdf");
	ifile = (ft_strlen(filename) - 4);
	while (filename[ifile] == ext[iext] && filename[ifile] && ext[iext])
	{
		ifile++;
		iext++;
	}
	if (filename[ifile] == '\0' && ext[iext] == '\0')
		return (1);
	else
		return (0);
}

void	arg_check(t_file file)
{
	if (file.argc != 2)
	{
		ft_putendl_fd(ARG_NUMBER, 2);
		exit(EXIT_FAILURE);
	}
	if (extension_checker(file.name) != 1)
	{
		ft_putendl_fd(FILE_EXT, 2);
		exit(EXIT_FAILURE);
	}
}
