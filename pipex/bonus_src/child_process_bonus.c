/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:19:55 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/14 15:54:09 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

void	child_process(t_fd *fd, char **envp, char *cmd)
{
	t_pars	pars;
	t_pid	child;

	pars.cmd = ft_strdup(cmd);
	pipe_or_not(fd);
	child.pid = fork();
	if (child.pid == 0)
	{
		wich_pipe_are_you(fd);
		check_for_error(fd->input);
		check_for_error(fd->output);
		exit_error(parsing_env(&pars, envp));
	}
	else
	{
		free(pars.cmd);
		if (fd->icmd != 2)
		{
			pipe_close(fd->io[FD_IN], fd->io[FD_OU]);
			fd->io[FD_IN] = fd->new_io[FD_IN];
			fd->io[FD_OU] = fd->new_io[FD_OU];
		}
	}
}

void	wich_pipe_are_you(t_fd *fd)
{
	if (fd->icmd == 2)
	{
		fd->input = dup2(fd->infile, 0);
		fd->output = dup2(fd->io[FD_IN], 1);
		pipe_close(fd->io[FD_OU], -1);
	}
	else if (fd->icmd == fd->ncmd + 1)
	{
		fd->input = dup2(fd->io[FD_OU], 0);
		fd->output = dup2(fd->outfile, 1);
		pipe_close(fd->io[FD_IN], -1);
	}
	else
	{
		fd->input = dup2(fd->io[FD_OU], 0);
		fd->output = dup2(fd->new_io[FD_IN], 1);
		pipe_close(fd->io[FD_IN], fd->new_io[FD_OU]);
	}
}

void	pipe_or_not(t_fd *fd)
{
	if (fd->icmd == 2)
	{
		check_for_error(pipe(fd->io));
		fd->npipe--;
	}
	else if (fd->npipe > 0)
	{
		check_for_error(pipe(fd->new_io));
		fd->npipe--;
	}
}

void	here_doc_first_child(t_fd *fd, char **envp, char *cmd)
{
	t_pars	doc_pars;

	fd->input = dup2(fd->io[FD_OU], 0);
	fd->output = dup2(fd->new_io[FD_IN], 1);
	pipe_close(fd->io[FD_IN], fd->new_io[FD_OU]);
	check_for_error(fd->input);
	check_for_error(fd->output);
	doc_pars.cmd = ft_strdup(cmd);
	exit_error(parsing_env(&doc_pars, envp));
}

void	here_doc_scnd_child(t_fd *fd, char **envp, char *cmd)
{
	t_pars	doc_pars;

	fd->input = dup2(fd->io[FD_OU], 0);
	fd->output = dup2(fd->outfile, 1);
	pipe_close(fd->io[FD_IN], -1);
	check_for_error(fd->input);
	check_for_error(fd->output);
	doc_pars.cmd = ft_strdup(cmd);
	exit_error(parsing_env(&doc_pars, envp));
}
