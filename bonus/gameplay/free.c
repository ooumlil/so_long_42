/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:29:01 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/12 05:10:40 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_free(t_game *g)
{
	int	i;

	i = 0;
	mlx_destroy_image(g->mlx, g->back);
	mlx_destroy_image(g->mlx, g->coll);
	mlx_destroy_image(g->mlx, g->exit);
	mlx_destroy_image(g->mlx, g->play);
	mlx_destroy_image(g->mlx, g->wall);
	mlx_destroy_image(g->mlx, g->enemy);
	while (g->map[i])
	{
		free(g->map[i]);
		i++;
	}
	free(g->map);
}

int	ft_exit(t_game *g)
{
	write(1, "You quit!\n", 10);
	ft_free(g);
	exit (0);
}

void	you_left(t_game *g)
{
	write(1, "You Left!\n", 10);
	ft_free(g);
	exit (0);
}

void	you_won(t_game *g)
{
	write(1, "You Won!\n", 9);
	ft_free(g);
	exit (0);
}

void	you_lost(t_game *g)
{
	write(1, "You Lost!\n", 10);
	ft_free(g);
	exit (0);
}
