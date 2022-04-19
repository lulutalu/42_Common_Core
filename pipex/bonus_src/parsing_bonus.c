/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:21:36 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/11 20:13:49 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex_bonus.h"

/* While loop trying to find the correct way to execute process */
int	parsing_env(t_pars *pars, char **envp)
{
	arg_tab_exec_fill(pars);
	split_path_line(pars, envp);
	pars->i = 0;
	while (pars->split[pars->i] != NULL)
	{
		if (ft_strchr(pars->arg[0], '/') == NULL)
		{
			pars->temp = ft_strjoin(pars->split[pars->i], "/");
			pars->path = ft_strjoin(pars->temp, pars->arg[0]);
		}
		else
			pars->path = pars->arg[0];
		if (access(pars->path, X_OK) == 0)
			execve(pars->path, pars->arg, envp);
		pars->i++;
	}
	error_flag_select(pars);
	return (0);
}

/* Function to fill pars->arg double array for execve second argument */
void	arg_tab_exec_fill(t_pars *pars)
{
	pars->split = ft_split(pars->cmd, ' ');
	pars->i = 0;
	while (pars->split[pars->i] != NULL)
		pars->i++;
	pars->arg = ft_calloc(pars->i + 1, sizeof(char **));
	pars->i = 0;
	while (pars->split[pars->i] != NULL)
	{
		pars->arg[pars->i] = ft_strdup(pars->split[pars->i]);
		pars->i++;
	}
	free_tab((void **)pars->split);
}

/* Function to find PATH line in environnment and splitting it */
void	split_path_line(t_pars *pars, char **envp)
{
	pars->i = 0;
	while (ft_strnstr(envp[pars->i], "PATH=", 5) == NULL)
		pars->i++;
	pars->path = ft_substr(envp[pars->i], 5, ft_strlen(envp[pars->i]) - 5);
	pars->split = ft_split(pars->path, ':');
	free(pars->path);
}

/* Selection of wich error code need to be return */
void	error_flag_select(t_pars *pars)
{
	if (ft_strchr(pars->cmd, '/') == NULL)
		exit_error(127);
	else if (pars->arg[1] != NULL)
	{
		if (ft_strchr(pars->arg[1], '/') != NULL)
			exit_error(127);
	}
	exit_error(1);
}
