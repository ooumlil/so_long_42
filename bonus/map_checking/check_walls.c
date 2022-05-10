/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 02:43:23 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/12 23:31:40 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	topline(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	lastline(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	leftside(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	rightside(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	checkone(char **map)
{
	if (!topline(map) && !lastline(map) && !leftside(map) && !rightside(map))
		return (0);
	write (2, "Error\nNot Surrounded by Walls!\n", 31);
	return (1);
}
