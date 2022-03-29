/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:57:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 06:35:23 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	exit_error(char *error)
{
	if (ft_strncmp(error, "", 2) == 0)
		perror("\e[1;91mError \e[0m");
	else
		ft_putstr_fd_count(error, 2);
	exit(EXIT_FAILURE);
}

void	input_file_permission(char *pathname)
{
	if (access(pathname, F_OK) == -1)
		exit_error("");
	if (access(pathname, R_OK) == -1)
		exit_error("");
}

void	ouput_file_permission(char *pathname)
{
	if (access(pathname, W_OK) == -1)
		exit_error("");
}
