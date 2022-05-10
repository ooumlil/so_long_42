/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:43:30 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/12 05:11:59 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	coin_count(t_game *g)
{
	g->count = 0;
	g->i = 0;
	while (g->map[g->i])
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			if (g->map[g->i][g->j] == 'C')
				g->count++;
			g->j++;
		}
		g->i++;
	}
	return (g->count);
}

void	right(t_game *g)
{
	if (g->map[g->x][g->y + 1] != '1' && g->map[g->x][g->y + 1] != 'E' \
		&& g->map[g->x][g->y + 1] != 'T')
	{
		g->map[g->x][g->y] = '0';
		g->map[g->x][g->y + 1] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"img/playerD.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x][g->y + 1] == 'E' && coin_count(g) == 0)
		you_won(g);
	else if (g->map[g->x][g->y + 1] == 'T')
		you_lost(g);
	if (coin_count(g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"img/exit1.xpm", &g->width, &g->height);
	mlx_print(g);
}

void	left(t_game *g)
{
	if (g->map[g->x][g->y - 1] != '1' && g->map[g->x][g->y - 1] != 'E' \
		&& g->map[g->x][g->y - 1] != 'T')
	{
		g->map[g->x][g->y] = '0';
		g->map[g->x][g->y - 1] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"img/playerA.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x][g->y - 1] == 'E' && coin_count(g) == 0)
		you_won(g);
	else if (g->map[g->x][g->y - 1] == 'T')
		you_lost(g);
	if (coin_count(g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"img/exit1.xpm", &g->width, &g->height);
	mlx_print(g);
}

void	up(t_game *g)
{
	if (g->map[g->x - 1][g->y] != '1' && g->map[g->x - 1][g->y] != 'E' \
		&& g->map[g->x - 1][g->y] != 'T')
	{
		g->map[g->x][g->y] = '0';
		g->map[g->x - 1][g->y] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"img/playerW.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x - 1][g->y] == 'E' && coin_count(g) == 0)
		you_won(g);
	else if (g->map[g->x - 1][g->y] == 'T')
		you_lost(g);
	if (coin_count(g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"img/exit1.xpm", &g->width, &g->height);
	mlx_print(g);
}

void	down(t_game *g)
{
	if (g->map[g->x + 1][g->y] != '1' && g->map[g->x + 1][g->y] != 'E' \
		&& g->map[g->x + 1][g->y] != 'T')
	{
		g->map[g->x][g->y] = '0';
		g->map[g->x + 1][g->y] = 'P';
		g->num++;
		g->play = mlx_xpm_file_to_image(g->mlx, \
			"img/playerS.xpm", &g->width, &g->height);
	}
	else if (g->map[g->x + 1][g->y] == 'E' && coin_count(g) == 0)
		you_won(g);
	else if (g->map[g->x + 1][g->y] == 'T')
		you_lost(g);
	if (coin_count(g) == 0)
		g->exit = mlx_xpm_file_to_image(g->mlx, \
			"img/exit1.xpm", &g->width, &g->height);
	mlx_print(g);
}
