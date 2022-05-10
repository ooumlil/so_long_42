/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:25:56 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/12 21:24:32 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	enemy_a(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'T')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	enemy_b(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'T')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	enemy_moving(t_game *g)
{
	int	i;

	g->a = enemy_a(g->map);
	g->b = enemy_b(g->map);
	i = rand() % 20;
	if (i == 1)
		up_e(g);
	else if (i == 2)
		down_e(g);
	else if (i == 3)
		left_e(g);
	else if (i == 4)
		right_e(g);
	coin_animation(g);
	mlx_print(g);
	return (0);
}
