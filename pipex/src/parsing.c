/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:40:08 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 20:52:47 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	parsing_env(t_pars *pars, char **envp)
{
	int	ret;
	int	test;

	test = 0;
	pars->i = 0;
	while (ft_strnstr(pars->env[pars->i], "PATH=", 5) == NULL)
		pars->i++;
	pars->arg = ft_calloc(3, sizeof(char *));
	pars->split = ft_split(pars->cmd, ' ');
	pars->arg[0] = ft_strdup(pars->split[0]);
	pars->arg[1] = ft_strdup(pars->split[1]);
	free_tab((void **)pars->split);
	pars->path = pars->env[pars->i];
	pars->split = ft_split(pars->path, ':');
	free_tab((void **)pars->env);
	pars->i = 0;
	while (pars->split[pars->i] != NULL)
	{
		pars->temp = ft_strjoin(pars->split[pars->i], "/");
		pars->path = ft_strjoin(pars->temp, pars->arg[0]);
		ret = access(pars->path, X_OK);
		if (ret == 0)
		{
			execve(pars->temp, pars->arg, envp);
		}
		free(pars->path);
		pars->i++;
	}
	free_tab((void **)pars->split);
	exit_error("");
}
