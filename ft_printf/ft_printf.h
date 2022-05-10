/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:39:16 by ooumlil           #+#    #+#             */
/*   Updated: 2021/12/25 18:11:17 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_u(unsigned int u);
int	ft_x(unsigned int x, int b);
int	ft_p(unsigned long p);
int	ft_printf(const char *s, ...);

#endif
