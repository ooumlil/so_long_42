/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:26:05 by ooumlil           #+#    #+#             */
/*   Updated: 2022/03/13 02:47:29 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_map	m;

	if (ac != 2)
	{
		write(2, "Error\n2 Arguments are needed!\n", 30);
		return (1);
	}
	check_extension(av[1]);
	m.fd = open(av[1], O_RDONLY);
	if (m.fd == -1)
	{
		write(2, "Error\nFile Does not exist!\n", 27);
		return (close(m.fd), 1);
	}
	m.map = map_filling(av);
	if (mapcheck_bonus(m.map))
		mlx_start(m.map);
	return (0);
}
