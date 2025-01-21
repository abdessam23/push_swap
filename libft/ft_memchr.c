/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhimi <abhimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:19:02 by abhimi            #+#    #+#             */
/*   Updated: 2024/10/29 20:02:36 by abhimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	b;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) s;
	b = (unsigned char) c;
	while (i < n)
	{
		if (p[i] == b)
			return (p + i);
		i++;
	}
	return (NULL);
}
