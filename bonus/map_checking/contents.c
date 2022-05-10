/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:04:27 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/12 23:31:07 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	rectangular(char **map)
{
	t_map	data;

	data.len = ft_strlen(map[0]);
	data.i = 0;
	while (map[data.i])
	{
		if (data.len != ft_strlen(map[data.i]))
		{
			write(2, "Error\nNot Rectangular!\n", 23);
			return (1);
		}
		data.i++;
	}
	return (0);
}

void	char_check(t_map *co, char **map)
{
	if (map[co->i][co->j] == 'C')
		co->c++;
	else if (map[co->i][co->j] == 'P')
		co->p++;
	else if (map[co->i][co->j] == 'E')
		co->e++;
	else if (map[co->i][co->j] == 'T')
		co->t++;
}

int	components(char **map)
{
	t_map	co;

	co.i = 0;
	co.c = 0;
	co.e = 0;
	co.p = 0;
	co.t = 0;
	while (map[co.i])
	{
		co.j = 0;
		while (map[co.i][co.j])
		{
			char_check(&co, map);
			co.j++;
		}
		co.i++;
	}
	if (co.c > 0 && co.e > 0 && co.t > 0 && co.p == 1)
		return (0);
	write(2, "Error\nMissing Characters!\n", 26);
	return (1);
}

int	imposters(char **map)
{
	t_map	ch;

	ch.i = 0;
	while (map[ch.i])
	{
		ch.j = 0;
		while (map[ch.i][ch.j])
		{
			if (map[ch.i][ch.j] != '1' && map[ch.i][ch.j] != '0'
				&& map[ch.i][ch.j] != 'P' && map[ch.i][ch.j] != 'C'
				&& map[ch.i][ch.j] != 'E' && map[ch.i][ch.j] != 'T')
			{
				write(2, "Error\nInvalid Characters!\n", 26);
				return (1);
			}
			ch.j++;
		}
		ch.i++;
	}
	return (0);
}

int	mapcheck_bonus(char **map)
{
	if (!checkone(map) && !rectangular(map)
		&& !components(map) && !imposters(map))
		return (1);
	return (0);
}
