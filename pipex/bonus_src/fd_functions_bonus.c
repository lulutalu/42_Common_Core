/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_functions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:21:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/11 23:29:57 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	end_fd_close(t_fd *fd)
{
	close(fd->input);
	close(fd->infile);
	close(fd->output);
	close(fd->outfile);
	close(fd->io[FD_IN]);
	close(fd->io[FD_OU]);
	close(fd->new_io[FD_IN]);
	close(fd->new_io[FD_OU]);
}

void	pipe_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
