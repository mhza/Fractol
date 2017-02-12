/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 20:49:19 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->tx = x + e->zoom * X1_DIFF_C;
		e->ty = y + e->zoom * Y1_DIFF_C;
	}
	else if (button == 4 || button == 5)
	{
		e->zoom = button == 4 ? e->zoom * 0.8 : e->zoom * 1.2;
		e->tx = x + e->zoom * X1_DIFF_C;
		e->ty = y + e->zoom * Y1_DIFF_C;
	}
	else if (button == 2)
	{
	// i = 0;
	// while (i < 1000)
	// {printf("button 2");
	// 	e->color->r += i * 10 + 100;
	// 	e->color->g += i * 10 + 10;
	// 	e->color->b += i * 10 + 50;
	// 	i++;
	// }
	}
	clear_and_draw(e);
	return (1);
}

int		mouse_motion(int x, int y, t_env *e)
{
	if (e->id_f != 1 && x < WIN_X && x > 0.9 * WIN_X && y < WIN_X && y > 0)
	{
		e->color->r += rand();
		e->color->g += rand();
		e->color->b += rand();
		clear_and_draw(e);
	}
	else if (!e->block && e->id_f == 1 && x < WIN_X && x > 0 && y < WIN_Y && y > 0)
	{
		e->re_c = (x) / e->zoom + X1;
		e->im_c = (y) / e->zoom + Y1;
		printf("Julia re(z0) = %f, im(z0) = %f\n", e->re_zo, e->im_zo);
		printf("x = %d, y = %d\n", x, y);
		clear_and_draw(e);
	}
	return (1);
}
