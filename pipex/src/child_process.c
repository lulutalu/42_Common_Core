/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:57:49 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 20:32:55 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	first_child(t_fd *fd, t_pars *pars, char **envp)
{
	fd->input = dup2(fd->input, STDIN_FILENO);
	if (fd->input < 0)
		exit_error("");
	fd->output = dup2(fd->io[FD_IN], STDOUT_FILENO);
	if (fd->output < 0)
		exit_error("");
	if (close(fd->io[FD_OU]) < 0)
		exit_error("");
	parsing_env(pars, envp);
}

void	scnd_child(t_fd *fd, t_pars *pars, char **envp)
{
	fd->input = dup2(fd->io[FD_OU], STDIN_FILENO);
	if (fd->input < 0)
		exit_error("");
	if (close(fd->io[FD_IN]) < 0)
		exit_error("");
	fd->output = dup2(fd->outfile, STDOUT_FILENO);
	if (fd->output < 0)
		exit_error("");
	parsing_env(pars, envp);
}
