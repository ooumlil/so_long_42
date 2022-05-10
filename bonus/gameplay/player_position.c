/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:42:05 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/12 05:11:05 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	player_x(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	player_y(char	**map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	player_moving(int key, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	g->x = player_x(g->map);
	g->y = player_y(g->map);
	if (key == A)
		left(g);
	else if (key == S)
		down(g);
	else if (key == D)
		right(g);
	else if (key == W)
		up(g);
	else if (key == ESC)
		you_left(g);
	return (0);
}
