/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:50:41 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/11 01:17:09 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	mlx_print(t_game *g)
{
	g->i = 0;
	while (g->map[g->i])
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			if (g->map[g->i][g->j] == '1')
				mlx_put_image_to_window(g->mlx, g->mlx_win, \
					g->wall, g->j * g->width, g->i * g->height);
			else if (g->map[g->i][g->j] == '0')
				mlx_put_image_to_window(g->mlx, g->mlx_win, \
					g->back, g->j * g->width, g->i * g->height);
			else if (g->map[g->i][g->j] == 'P')
				mlx_put_image_to_window(g->mlx, g->mlx_win, \
					g->play, g->j * g->width, g->i * g->height);
			else if (g->map[g->i][g->j] == 'C')
				mlx_put_image_to_window(g->mlx, g->mlx_win, \
					g->coll, g->j * g->width, g->i * g->height);
			else if (g->map[g->i][g->j] == 'E')
				mlx_put_image_to_window(g->mlx, g->mlx_win, \
					g->exit, g->j * g->width, g->i * g->height);
		g->j++;
		}
	g->i++;
	}	
}

void	mlx_start(char **map)
{
	t_game	g;

	g.len = (int)ft_strlen(map[0]);
	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, g.len * 50, lines(map) * 50, "so_long");
	g.wall = mlx_xpm_file_to_image(g.mlx, "img/wall.xpm", &g.width, &g.height);
	g.back = mlx_xpm_file_to_image(g.mlx, "img/back.xpm", &g.width, &g.height);
	g.play = mlx_xpm_file_to_image(g.mlx, \
		"img/playerS.xpm", &g.width, &g.height);
	g.coll = mlx_xpm_file_to_image(g.mlx, "img/coin0.xpm", &g.width, &g.height);
	g.exit = mlx_xpm_file_to_image(g.mlx, "img/exit0.xpm", &g.width, &g.height);
	g.map = map;
	g.count = 0;
	g.num = 0;
	mlx_hook(g.mlx_win, 2, 1L << 0, player_moving, &g);
	mlx_hook(g.mlx_win, 17, 0, ft_exit, &g);
	mlx_print(&g);
	mlx_loop(g.mlx);
}
