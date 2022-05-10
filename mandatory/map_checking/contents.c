/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 01:04:27 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/13 02:53:40 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	components(char **map)
{
	t_map	content;

	content.c = 0;
	content.e = 0;
	content.p = 0;
	content.i = 0;
	while (map[content.i])
	{
		content.j = 0;
		while (map[content.i][content.j])
		{
			if (map[content.i][content.j] == 'C')
				content.c++;
			if (map[content.i][content.j] == 'P')
				content.p++;
			if (map[content.i][content.j] == 'E')
				content.e++;
			content.j++;
		}
		content.i++;
	}
	if (content.c > 0 && content.e > 0 && content.p == 1)
		return (0);
	write(2, "Error\nInvalid Content!\n", 23);
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
				&& map[ch.i][ch.j] != 'E')
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

int	mapcheck(char **map)
{
	if (!checkone(map) && !rectangular(map)
		&& !components(map) && !imposters(map))
		return (1);
	return (0);
}
