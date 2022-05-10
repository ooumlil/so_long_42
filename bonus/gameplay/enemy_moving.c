/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:06:59 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/12 05:12:30 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	up_e(t_game *g)
{
	if (g->map[g->a - 1][g->b] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a - 1][g->b] = 'T';
		g->enemy = mlx_xpm_file_to_image(g->mlx, \
			"img/enemy_up.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a - 1][g->b] == 'P')
		you_lost(g);
}

void	down_e(t_game *g)
{
	if (g->map[g->a + 1][g->b] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a + 1][g->b] = 'T';
		g->enemy = mlx_xpm_file_to_image(g->mlx, \
			"img/enemy_down.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a + 1][g->b] == 'P')
		you_lost(g);
}

void	right_e(t_game *g)
{
	if (g->map[g->a][g->b + 1] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a][g->b + 1] = 'T';
		g->enemy = mlx_xpm_file_to_image(g->mlx, \
			"img/enemy_right.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a][g->b + 1] == 'P')
		you_lost(g);
}

void	left_e(t_game *g)
{
	if (g->map[g->a][g->b - 1] == '0')
	{
		g->map[g->a][g->b] = '0';
		g->map[g->a][g->b - 1] = 'T';
		g->enemy = mlx_xpm_file_to_image(g->mlx, \
			"img/enemy_left.xpm", &g->width, &g->height);
	}
	else if (g->map[g->a][g->b - 1] == 'P')
		you_lost(g);
}
