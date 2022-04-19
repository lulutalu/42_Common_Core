/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:14:16 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/06 18:08:27 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	t_pid	first;
	t_pid	scnd;
	t_pars	pars;

	number_arg_check(argc);
	start_fd_open(&fd, argv[1], argv[4]);
	check_for_error(pipe(fd.io));
	first.pid = fork();
	check_for_error(first.pid);
	if (first.pid == 0)
		first_child(&fd, &pars, envp, argv[2]);
	scnd.pid = fork();
	check_for_error(scnd.pid);
	if (scnd.pid == 0)
		scnd_child(&fd, &pars, envp, argv[3]);
	end_fd_close(&fd);
	waitpid(first.pid, &first.status, 0);
	waitpid(scnd.pid, &scnd.status, 0);
	if (WIFEXITED(scnd.status) != 0)
		exit(WEXITSTATUS(scnd.status));
	exit(0);
}
