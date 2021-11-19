/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:09:15 by lduboulo          #+#    #+#             */
/*   Updated: 2021/11/19 12:29:40 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "get_next_line_bonus.h"
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
void	*ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char **s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char **s1, int istr);

#endif
