/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/23 17:57:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	float tmp;

	if (button == 2 && y > 0)
	{
		e->tx = -WIN_X / 2;
		e->ty = -WIN_Y / 2;
		clear_and_draw(e);
	}
	else if (button == 1 && y > 0)
	{
		e->tx += (x - WIN_X / 2);
		e->ty += (y - WIN_Y / 2);
		clear_and_draw(e);
	}
	else if (button == 4 || button == 5)
	{
		tmp = e->zoom;
		e->zoom = button == 5 ? e->zoom * 0.8 : e->zoom * 1.2;
		e->tx = button == 5 ? e->tx + (float)ABS(WIN_X / 2 - x) * (1 / e->zoom - 1 / tmp) :
		e->tx - (float)ABS(WIN_X / 2 - x) * (1 / e->zoom - 1 / tmp);
		e->ty = button == 5 ? e->ty + (float)ABS(WIN_Y / 2 - y) * (1 / e->zoom - 1 / tmp) :
		e->ty - (float)ABS(WIN_Y / 2 - y) * (1 / e->zoom - 1 / tmp);
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
