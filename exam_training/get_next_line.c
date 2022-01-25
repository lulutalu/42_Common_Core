/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:51:02 by lduboulo          #+#    #+#             */
/*   Updated: 2022/01/25 12:57:30 by lduboulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_bzero(void *s, int size)
{
	int	i;

	i = 0;
	while (size-- > 0)
		((char*)s)[i++] = '\0';
	return (s);
}

void	*gnl_calloc(int count, int size)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ptr = gnl_bzero(ptr, count * size);
	return (ptr);
}

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char **s1, char *s2)
{
	int		i1;
	int		i2;
	char	*res;
	int		ir;

	i1 = 0;
	i2 = 0;
	ir = 0;
	res = gnl_calloc(gnl_strlen(*s1) + gnl_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while ((*s1)[i1])
		res[ir++] = (*s1)[i1++];
	while (s2[i2])
		res[ir++] = s2[i2++];
	free(*s1);
	return (res);
}

char	*gnl_substr(char *s, int start, int final)
{
	char	*res;
	int		ir;

	ir = 0;
	res = gnl_calloc(final - start + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (start < final)
		res[ir++] = s[start++];
	return (res);
}

char	*gnl_strdup(char **s, int i)
{
	char	*res;
	int		ir;

	ir = 0;
	res = gnl_calloc(gnl_strlen(*s) - i + 1, sizeof(char));
	if (!res)
		return (NULL);
	while ((*s)[i])
		res[ir++] = (*s)[i++];
	free(*s);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*res;
	char		buffer[BUFFER_SIZE + 1];
	int			i;
	int			nb;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!save)
		save = gnl_calloc(1, sizeof(char));
	i = 0;
	while (1)
	{
		gnl_bzero(buffer, BUFFER_SIZE + 1);
		nb = read(fd, buffer, BUFFER_SIZE);
		save = gnl_strjoin(&save, buffer);
		if (nb > 0)
		{
			while (save[i] != '\n' && save[i])
				i++;
			if (save[i] == '\n')
			{
				res = gnl_substr(save, 0, ++i);
				save = gnl_strdup(&save, i);
				return (res);
			}
		}
		else if (save[0] == '\0')
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		else
		{
			while (save[i] != '\n' && save[i] != '\0')
				i++;
			if (save[i] == '\n')
			{
				res = gnl_substr(save, 0, ++i);
				save = gnl_strdup(&save, i);
				return (res);
			}
			if (save[i] == '\0')
			{
				res = gnl_substr(save, 0, ++i);
				free(save);
				save = NULL;
				return (res);
			}
		}
	}
}

/*int	main()
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i++ < 10)
		printf("%s", get_next_line(fd));
}*/
