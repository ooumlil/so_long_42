/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:08:31 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/14 01:01:40 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	xpm_to_img(t_game *g)
{
	g->wall = mlx_xpm_file_to_image(g->mlx, \
		"img/wall.xpm", &g->width, &g->height);
	g->back = mlx_xpm_file_to_image(g->mlx, \
		"img/back.xpm", &g->width, &g->height);
	g->play = mlx_xpm_file_to_image(g->mlx, \
		"img/playerS.xpm", &g->width, &g->height);
	g->coll = mlx_xpm_file_to_image(g->mlx, \
		"img/coin0.xpm", &g->width, &g->height);
	g->exit = mlx_xpm_file_to_image(g->mlx, \
		"img/wall.xpm", &g->width, &g->height);
	g->enemy = mlx_xpm_file_to_image(g->mlx, \
		"img/enemy_down.xpm", &g->width, &g->height);
}

void	my_mlx_image_put(t_game *g)
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
	else if (g->map[g->i][g->j] == 'T')
		mlx_put_image_to_window(g->mlx, g->mlx_win, \
			g->enemy, g->j * g->width, g->i * g->height);
}

void	coin_animation(t_game *g)
{
	static int	i;

	if (i <= 10)
		g->coll = mlx_xpm_file_to_image(g->mlx, \
			"img/coin0.xpm", &g->width, &g->height);
	else if (i <= 20)
		g->coll = mlx_xpm_file_to_image(g->mlx, \
			"img/coin1.xpm", &g->width, &g->height);
	else if (i <= 30)
		g->coll = mlx_xpm_file_to_image(g->mlx, \
			"img/coin2.xpm", &g->width, &g->height);
	else if (i <= 40)
		g->coll = mlx_xpm_file_to_image(g->mlx, \
			"img/coin3.xpm", &g->width, &g->height);
	else if (i <= 50)
		g->coll = mlx_xpm_file_to_image(g->mlx, \
			"img/coin4.xpm", &g->width, &g->height);
	else if (i <= 60)
		g->coll = mlx_xpm_file_to_image(g->mlx, \
			"img/coin5.xpm", &g->width, &g->height);
	i++;
	if (i == 60)
		i = 0;
}

void	mlx_print(t_game *g)
{
	char	*s;

	s = ft_itoa(g->num);
	g->i = 0;
	while (g->map[g->i])
	{
		g->j = 0;
		while (g->map[g->i][g->j])
		{
			my_mlx_image_put(g);
		g->j++;
		}
	g->i++;
	}	
	mlx_string_put(g->mlx, g->mlx_win, 10, 10, 0x0042f5a7, "Moves");
	mlx_string_put(g->mlx, g->mlx_win, 100, 10, 0x0042f5a7, s);
	free(s);
}

void	mlx_start(char **map)
{
	t_game	g;

	g.len = (int)ft_strlen(map[0]);
	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, g.len * 50, lines(map) * 50, \
		"so_long_bonus");
	xpm_to_img(&g);
	g.map = map;
	g.num = 0;
	g.loop = 0;
	mlx_hook(g.mlx_win, 2, 1L << 0, player_moving, &g);
	mlx_loop_hook(g.mlx, enemy_moving, &g);
	mlx_hook(g.mlx_win, 17, 0, ft_exit, &g);
	mlx_print(&g);
	mlx_loop(g.mlx);
}
