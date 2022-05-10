/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:21:57 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/13 02:52:04 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_extension(char *av)
{
	size_t	i;

	i = ft_strlen(av);
	if (av[i - 1] == 'r' && av[i - 2] == 'e' \
		&& av[i - 3] == 'b' && av[i - 4] == '.')
		return ;
	else
	{
		write (2, "Error\nWrong Extension!\n", 23);
		exit (1);
	}
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*c;

	i = 0;
	l = ft_strlen(s1);
	c = (char *)malloc(sizeof(char) * l + 1);
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(s + start))
		str = malloc(len + 1);
	else
		str = malloc(ft_strlen(s) - start + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

int	num_of_lines(char **av)
{
	t_map	m;

	m.i = 0;
	m.fd = open(av[1], O_RDONLY);
	while (1)
	{
		m.tmp = get_next_line(m.fd);
		free (m.tmp);
		if (!m.tmp)
			break ;
		m.i++;
	}
	return (close(m.fd), m.i);
}

char	**map_filling(char **av)
{
	t_map	m;

	m.line = num_of_lines(av);
	m.map = (char **)malloc(sizeof(char *) * m.line + 1);
	if (!m.map)
		return (NULL);
	m.fd = open(av[1], O_RDONLY);
	m.i = -1;
	while (++m.i < m.line)
		m.map[m.i] = get_next_line(m.fd);
	m.i = -1;
	while (++m.i < m.line - 1)
	{
		m.tmp2 = m.map[m.i];
		m.map[m.i] = ft_substr(m.tmp2, 0, ft_strlen(m.tmp2) - 1);
		free (m.tmp2);
	}
	m.i++;
	m.map[m.i] = NULL;
	if (!m.map)
		return (NULL);
	return (close(m.fd), m.map);
}
