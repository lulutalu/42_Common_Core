/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:42:21 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 20:52:49 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
 * Default Library
*/

# include "pipex.h"
# include "ft_printf.h"
# include "get_next_line.h"

/*
 * Authorized Function Library's
*/

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

/*
 * Error Messages Macro
*/

# define N_ARGS "\e[1;91mNumber of arguments incorrect\n\e[0m"
# define FD_IN 1
# define FD_OU 0

/*
 * Structures
*/

typedef struct s_pid
{
	pid_t	pid;
	int		status;
}				t_pid;

typedef struct s_fd
{
	int		io[2];
	int		input;
	int		output;
	int		outfile;
}				t_fd;

typedef struct s_pars
{
	char	**env;
	int		i;
	char	**split;
	char	*cmd;
	char	**arg;
	char	*path;
	char	**exec;
	char	*temp;
}				t_pars;

/*
 * Errors and Memory Functions
*/

void	exit_error(char *error);
void	free_tab(void **mem);

/*
 * Fork Functions
*/

void	first_child(t_fd *fd, t_pars *pars, char **envp);
void	scnd_child(t_fd *fd, t_pars *pars, char **envp);

/*
 * Parsing Functions
*/

void	parsing_env(t_pars *pars, char **envp);

#endif
