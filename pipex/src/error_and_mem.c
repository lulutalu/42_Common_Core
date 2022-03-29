/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 04:57:11 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 19:25:48 by lduboulo         ###   ########.fr       */
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

void	free_tab(void **mem)
{
	int	i;

	i = 0;
	while (mem[i] != NULL)
		i++;
	while (i > 0)
		free(mem[i--]);
	free(mem);
}
