/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:12 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/03 21:28:31 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		iline;
	int		imap;
	int		nbline;
	char	**map;
	t_file	file;

	file.name = argv[1];
	file.argc = argc;
	line = ft_calloc(1, sizeof(char));
	arg_check(file);
	file_desc_opening(&file);
	nbline = 0;
	while (line != NULL)
	{
		line = get_next_line(file.fd);
		nbline++;
	}
	free(line);
	map = ft_calloc((nbline + 1), sizeof(char *));
	file_desc_closing(&file);
	file_desc_opening(&file);
	imap = 0;
	while (imap < nbline)
	{
		line = get_next_line(file.fd);
		map[imap] = ft_calloc((ft_strlen(line) + 1), sizeof(char));
		iline = 0;
		while (line[iline])
		{
			map[imap][iline] = line[iline];
			iline++;
		}
		imap++;
	}
	return (1);
}
