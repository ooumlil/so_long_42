/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:22:42 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/10 00:05:32 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
		s[i++] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		ls2;
	int		lstr;
	int		i;
	char	*str;

	ls2 = 0;
	while (s2[ls2] && s2[ls2] != '\n')
		ls2++;
	if (s2[ls2] == '\n')
		ls2++;
	str = malloc(ft_strlen(s1) + ls2 + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	lstr = ft_strlen(str);
	i = 0;
	while (i < ls2)
	{
		str[lstr + i] = s2[i];
		i++;
	}
	str[lstr + i] = 0;
	free(s1);
	return (str);
}
