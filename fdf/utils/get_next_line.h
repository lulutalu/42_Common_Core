/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:58:08 by lduboulo          #+#    #+#             */
/*   Updated: 2021/12/30 20:48:41 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include "./fdf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*line_return(char **str, int i);
char	*no_read(char **str);
char	*buffer_not_empty(char **str, int i);
char	*read_loop(int fd, char **str);
void	*gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char **s1, char const *s2);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strdup(char **s1, int istr);

#endif
