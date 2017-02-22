/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/22 19:23:09 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
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
		// printf(">>>\nold e->zoom %.2f\n", e->zoom);
		// printf("e->tx %.2f\n", e->tx);
		// printf("e->ty %.2f\n", e->ty);
		// printf("old x %.0f  new x %i\n", e->x, x);
		// printf("old y %.0f  new y %i\n", e->y, y);
		float tmp = e->zoom;
		e->zoom = button == 5 ? e->zoom * 0.8 : e->zoom * 1.2;
		// printf("new e->zoom %.2f\n", e->zoom);
		e->x = e->x * e->y == 1 ? x : e->x;
		e->y = e->x * e->y == 1 ? y : e->y;
		e->tx = button == 5 ? e->tx + ((x / tmp - x / e->zoom)) * e->zoom : e->tx - e->zoom * ((x - WIN_X / 2) / tmp - (x - WIN_X / 2) / e->zoom);
		e->ty = button == 5 ? e->ty + ((y / tmp - y / e->zoom)) * e->zoom : e->ty - e->zoom * ((y - WIN_Y / 2) / tmp - (y - WIN_Y / 2) / e->zoom);
		// printf("e->tx %.2f\n", e->tx);
		// printf("e->ty %.2f\n", e->ty);

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
