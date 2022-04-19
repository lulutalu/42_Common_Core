/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:15:47 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/14 15:59:59 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/*
 * Default Library
*/

# include "pipex_bonus.h"
# include "utils.h"
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
	int		new_io[2];
	int		input;
	int		infile;
	int		output;
	int		outfile;
	int		icmd;
	int		ncmd;
	int		npipe;
}				t_fd;

typedef struct s_pars
{
	int		i;
	char	**split;
	char	**exec;
	char	**arg;
	char	*cmd;
	char	*path;
	char	*temp;
}				t_pars;

typedef struct s_doc
{
	char	*buf;
	char	*here_doc;
	char	*limiter;
	t_pid	doc_child;
}				t_doc;

/*
 * Errors and Memory Functions
*/

void	exit_error(int status);
void	free_tab(void **mem);
void	check_for_error(int value);
void	free_here_doc(t_doc *doc);

/*
 * File descriptor opening and closing
*/

void	end_fd_close(t_fd *fd);
void	pipe_close(int fd1, int fd2);

/*
 * Fork Functions multi pipes
*/

void	child_process(t_fd *fd, char **envp, char *cmd);
void	pipe_or_not(t_fd *fd);
void	wich_pipe_are_you(t_fd *fd);

/*
 * Fork Functions here_doc
*/

void	here_doc_first_child(t_fd *fd, char **envp, char *cmd);
void	here_doc_scnd_child(t_fd *fd, char **envp, char *cmd);

/*
 * Main operations sub-functions
*/

void	multi_pipes_process(t_fd *fd, char **envp, char **argv, int argc);
void	here_doc_process(t_doc *doc, t_fd *fd, char **envp, char **argv);

/*
 * Parsing Functions
*/

int		parsing_env(t_pars *pars, char **envp);
void	arg_tab_exec_fill(t_pars *pars);
void	split_path_line(t_pars *pars, char **envp);
void	error_flag_select(t_pars *pars);

#endif
