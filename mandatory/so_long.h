/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:24:00 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/14 01:05:56 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_map {
	int		i;
	int		j;
	size_t	len;
	size_t	pos;
	int		line;
	int		c;
	int		e;
	int		p;
	int		o;
	int		fd;
	char	**map;
	char	*tmp;
	char	*tmp2;
}				t_map;

typedef struct s_game {
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;
	int		width;
	int		height;
	int		count;
	int		num;
	int		len;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*back;
	void	*coll;
	void	*play;
	void	*exit;
}				t_game;

size_t	ft_strlen(const char *s);
void	check_extension(char *av);
char	*get_next_line(int fd);
void	ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(char *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		num_of_lines(char **av);
char	**map_filling(char **av);
int		firstline(char **map);
int		lastline(char **map);
int		leftside(char **map);
int		rightside(char **map);
int		checkone(char **map);
int		rectangular(char **map);
int		components(char **map);
int		imposters(char **map);
int		mapcheck(char **map);
void	mlx_start(char **map);
int		lines(char **map);
void	mlx_print(t_game *g);
int		player_x(char **map);
int		player_y(char **map);
int		coin_count(t_game *g);
void	move_right(t_game *g);
void	move_left(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
int		player_moving(int key, void *param);
int		ft_exit(t_game *g);
void	ft_free(t_game *g);
void	you_lost(t_game *g);
void	you_won(t_game *g);
void	you_left(t_game *g);

#endif