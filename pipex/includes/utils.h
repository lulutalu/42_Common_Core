/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:06:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/04/12 17:16:42 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include "utils.h"
# include "get_next_line.h"
# include <stdarg.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);
void	ft_putnbr_fd_count(long n, int fd, int *count);
char	*ft_strdup(const char *s1);
void	*ft_bzero(void *s, size_t n);
void	*ft_itoa_base(char **res, unsigned long n, char const *base);
int		ft_putchar_fd_count(char c, int fd);
int		ft_putstr_fd_count(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_dyn_strjoin(char *dynstr, char const *s2);

#endif
