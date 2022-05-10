/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:26:10 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/10 00:05:36 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	ft_read_fd(int fd, char **line)
{
	static char	buff[1];
	int			ret;
	size_t		len;

	if (buff[0] == '\0')
	{
		ret = read(fd, buff, 1);
		buff[ret] = '\0';
		if (ret < 1)
		{
			if (ret == -1)
				ft_bzero(*line, 1);
			return (0);
		}
	}
	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	*line = ft_strjoin(*line, buff);
	ft_strcpy(buff, &buff[len]);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*l;

	l = malloc(1);
	if (!l)
		return (NULL);
	l[0] = '\0';
	while (!ft_strchr(l, '\n'))
		if (!ft_read_fd(fd, &l))
			break ;
	if (l[0] == '\0')
	{
		free (l);
		return (0);
	}
	return (l);
}
