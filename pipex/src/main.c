/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:14:16 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 06:36:40 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	main(int argc, char **argv)
{
	int		io[2];
	pid_t	child_1;
	pid_t	child_2;

	if (argc == 5)
	{
		input_file_permission(argv[1]);
		if (open(argv[1], O_RDONLY) < 0)
			exit_error("");
		if (open(argv[4], O_RDWR | O_CREAT) < 0)
			exit_error("");
		if (pipe(io) < 0)
			exit_error("");
		child_1 = fork();
		if (child_1 < 0)
			exit_error("");
		child_2 = fork();
		if (child_2 < 0)
			exit_error("");
	}
	else
		exit_error(N_ARGS);
	return (0);
}
