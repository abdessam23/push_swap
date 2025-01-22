/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:35:58 by abhimi            #+#    #+#             */
/*   Updated: 2025/01/22 15:48:11 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	char	*l;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	l = (char *)malloc(sizeof(char) * (i + 2));
	if (!l)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		l[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		l[i] = str[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	*ft_add(char *p)
{
	char	*st;
	int		i;
	int		j;

	i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	if (!p[i])
	{
		free(p);
		return (NULL);
	}
	st = malloc(sizeof(char) * (ft_strlen(p) - i + 1));
	if (!st)
		return (NULL);
	i++;
	j = 0;
	while (p[i])
		st[j++] = p[i++];
	st[j] = '\0';
	free(p);
	return (st);
}

char	*read_sv(int fd, char *s)
{
	char	*b;
	int		rbyt;

	b = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!b)
		return (NULL);
	rbyt = 1;
	while (!ft_strchr(s, '\n') && rbyt != 0)
	{
		rbyt = read(fd, b, BUFFER_SIZE);
		if (rbyt == -1)
			return (free(s), free(b), NULL);
		b[rbyt] = '\0';
		if (rbyt == 0)
			break ;
		s =	ft_gstrjoin(s, b);
	}
	free(b);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*b;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b = read_sv(fd, b);
	if (!b)
		return (NULL);
	ln = ft_get_line(b);
	b = ft_add(b);
	return (ln);
}