/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:17:40 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/14 16:17:45 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	t_doc	doc;

	if (argc < 5)
	{
		ft_putstr_fd_count(N_ARGS, 2);
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		doc.limiter = ft_strjoin(argv[2], "\n");
		doc.here_doc = ft_calloc(1, sizeof(char));
		fd.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		check_for_error(fd.outfile);
		while (1)
			here_doc_process(&doc, &fd, envp, argv);
	}
	else
		multi_pipes_process(&fd, envp, argv, argc);
	end_fd_close(&fd);
	exit(0);
}
