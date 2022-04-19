/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:24:30 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/14 16:17:43 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	multi_pipes_process(t_fd *fd, char **envp, char **argv, int argc)
{
	fd->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	fd->infile = open(argv[1], O_RDONLY);
	check_for_error(fd->outfile);
	check_for_error(fd->infile);
	if (fd->infile < 0)
	{
		ft_putstr_fd_count("No such file or directory\n", 2);
		exit(1);
	}
	fd->ncmd = argc - 3;
	fd->npipe = fd->ncmd - 1;
	fd->icmd = 2;
	while (fd->icmd < (fd->ncmd + 2))
	{
		child_process(fd, envp, argv[fd->icmd]);
		fd->icmd++;
	}
}

void	here_doc_process(t_doc *doc, t_fd *fd, char **envp, char **argv)
{
	ft_putstr_fd_count("pipe heredoc> ", 1);
	doc->buf = get_next_line(0);
	if (ft_strncmp(doc->buf, doc->limiter, ft_strlen(doc->buf)) == 0)
	{
		check_for_error(pipe(fd->io));
		ft_putstr_fd_count(doc->here_doc, fd->io[FD_IN]);
		check_for_error(pipe(fd->new_io));
		doc->doc_child.pid = fork();
		if (doc->doc_child.pid == 0)
			here_doc_first_child(fd, envp, argv[3]);
		else
		{
			pipe_close(fd->io[FD_IN], fd->io[FD_OU]);
			fd->io[FD_IN] = fd->new_io[FD_IN];
			fd->io[FD_OU] = fd->new_io[FD_OU];
		}
		doc->doc_child.pid = fork();
		if (doc->doc_child.pid == 0)
			here_doc_scnd_child(fd, envp, argv[4]);
		end_fd_close(fd);
		free_here_doc(doc);
		exit(0);
	}
	doc->here_doc = ft_dyn_strjoin(doc->here_doc, doc->buf);
	free(doc->buf);
}
