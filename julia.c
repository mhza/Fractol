/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:56:17 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/22 13:27:23 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_env *e, int x, int y)
{
	t_cplex	z;
	t_cplex	c;
	float	mod;
	float	tmp;
	int		i;

	i = 0;
	z.re = 0;
	z.im = 0;
	c.re = (x + e->tx) / e->zoom;
	c.im = (y + e->ty) / e->zoom;
	e->re_c = c.re;
	e->im_c = c.im;
	mod = 0;
	while (i < e->iter && (mod < 4))
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		mod = z.re * z.re + z.im * z.im;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

int		julia(t_env *e, int x, int y)
{
	t_cplex	z;
	t_cplex	c;
	float	mod;
	float	tmp;
	int		i;

	i = 0;
	z.re = (x + e->tx) / e->zoom;
	z.im = (y + e->ty) / e->zoom;
	c.re = e->re_c;
	c.im = e->im_c;
	mod = 0;
	while (i < e->iter && (mod < 4))
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		mod = z.re * z.re + z.im * z.im;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}

int		burnship(t_env *e, int x, int y)
{
	t_cplex	z;
	t_cplex	c;
	float	mod;
	float	tmp;
	int		i;

	i = 0;
	z.re = 0;
	z.im = 0;
	c.re = (x + e->tx) / e->zoom;
	c.im = (y + e->ty) / e->zoom;
	mod = 0;
	while (i < e->iter && (mod < 4))
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * fabsf(tmp * z.im) + c.im;
		mod = z.re * z.re + z.im * z.im;
		i++;
	}
	if (i == e->iter)
		return (0);
	return (i);
}
