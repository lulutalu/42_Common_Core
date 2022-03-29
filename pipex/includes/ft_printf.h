/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:06:52 by lduboulo          #+#    #+#             */
/*   Updated: 2022/03/29 06:02:17 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include "pipex.h"
# include <stdarg.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct printf_list
{
	int		count;
	int		i;
	va_list	arg;
	char	*str;
	int		nbvar;
	char	*param;
	int		iparam;
}				t_printf;

void	core_process(t_printf *ptr, const char *input);
void	hexa_process(t_printf *ptr, int flag);
void	string_process(t_printf *ptr);
void	pointer_address_process(t_printf *ptr);
void	variable_counter(t_printf *ptr, const char *input);
void	struct_init(t_printf *ptr);
void	if_forest(const char *input, t_printf *ptr);
int		ft_printf(const char *input, ...);
void	*ft_calloc(size_t count, size_t size);
void	ft_putnbr_fd_count(long n, int fd, int *count);
char	*ft_strdup(const char *s1);
void	*ft_bzero(void *s, size_t n);
void	*ft_itoa_base(char **res, unsigned long n, char const *base);
int		ft_putchar_fd_count(char c, int fd);
int		ft_putstr_fd_count(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
