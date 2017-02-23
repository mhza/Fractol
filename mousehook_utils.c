/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/23 11:08:50 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	float tmp;

	if (button == 2 && y > 0)
	{
		e->tx = x + e->zoom * ABSX;
		e->ty = y + e->zoom * ABSY;
		clear_and_draw(e);
	}
	else if (button == 1 && y > 0)
	{
		e->tx = x + e->zoom * X1_DIFF_C;
		e->ty = y + e->zoom * Y1_DIFF_C;
		clear_and_draw(e);
	}
	else if (button == 4 || button == 5)
	{
		tmp = e->zoom;
		e->zoom = button == 5 ? e->zoom * 0.8 : e->zoom * 1.2;
		e->tx = button == 5 ? x * (tmp / e->zoom - 1) - WIN_X / 2 :
		-x * (tmp / e->zoom - 1) - WIN_X / 2;
		e->ty = button == 5 ? y * (tmp / e->zoom - 1) - WIN_Y / 2 :
		-y * (tmp / e->zoom - 1) - WIN_Y / 2;
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
