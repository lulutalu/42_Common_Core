/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:42:21 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 06:35:24 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
 * Default Library
*/

# include "pipex.h"
# include "ft_printf.h"

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
# define FD_IN 0
# define FD_OU 1

/*
 * Functions
*/

void	exit_error(char *error);
void	input_file_permission(char *pathname);
void	ouput_file_permission(char *pathname);

#endif
