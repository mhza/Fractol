/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/15 13:53:31 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->tx = x + e->zoom * X1_DIFF_C;
		e->ty = y + e->zoom * Y1_DIFF_C;
		clear_and_draw(e);
	}
	else if (button == 4 || button == 5)
	{
		e->zoom = button == 5 ? e->zoom * 0.8 : e->zoom * 1.2;
		e->x = e->x * e->y == 1 ? x : e->x;
		e->y = e->x * e->y == 1 ? y : e->y;
		e->tx = (1 - e->zoom / ZOOM_INIT) * ((float)x - e->x)
		- e->zoom / (ZOOM_INIT) * (x - e->x);
		e->ty = (1 - e->zoom / ZOOM_INIT) * ((float)y - e->y)
		- e->zoom / (ZOOM_INIT) * (y - e->y);
		e->x = x;
		e->y = y;
		clear_and_draw(e);
	}
	return (1);
}

int		mouse_motion(int x, int y, t_env *e)
{
	if ((e->id_f != 1 || e->block) &&
		x < WIN_X && x > 0 && y < WIN_Y && y > WIN_Y - 20)
	{
		e->color->r += rand();
		e->color->g += rand();
		e->color->b += rand();
	}
	else if (!e->block && e->id_f == 1
			&& x < WIN_X && x > 0 && y < WIN_Y && y > 0)
	{
		e->re_c = (x) / e->zoom + X1;
		e->im_c = (y) / e->zoom + Y1;
	}
	clear_and_draw(e);
	return (1);
}
