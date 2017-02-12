/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 23:39:46 by mhaziza          ###   ########.fr       */
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
	clear_and_draw(e);
	return (1);
}

int		mouse_motion(int x, int y, t_env *e)
{
	if (e->id_f != 1 && x < WIN_X / 5 && x > 0 && y < WIN_X / 10 && y > 0)
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
