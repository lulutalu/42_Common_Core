/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:51:43 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/25 12:57:31 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

void	*gnl_bzero(void *s, int size);
void	*gnl_calloc(int count, int size);
int		gnl_strlen(char *str);
char	*gnl_strjoin(char **s1, char *s2);
char	*gnl_substr(char *s, int start, int final);
char	*gnl_strdup(char **s, int i);
char	*get_next_line(int fd);

# endif
