/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:34:03 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/04 17:21:27 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	start_fd_open(t_fd *fd, char *in, char *out)
{
	fd->input = open(in, O_RDONLY);
	fd->outfile = open(out, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd->outfile < 0 || fd->input < 0)
		ft_putstr_fd_count("No such file or directory\n", 2);
}

void	end_fd_close(t_fd *fd)
{
	close(fd->input);
	close(fd->output);
	close(fd->outfile);
	close(fd->io[FD_IN]);
	close(fd->io[FD_OU]);
}
