/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:35:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 23:32:21 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_hook_color(int keycode, t_env *e)
{
	if (keycode == 11)
		e->color->r += 10;
	else if (keycode == 5)
		e->color->g += 10;
	else if (keycode == 15)
		e->color->b += 10;
	else if (keycode == 17)
	{
		e->color->r += 10;
		e->color->g += 50;
		e->color->b += 90;
	}
	else if (keycode == 6)
	{
		e->color->r = 0;
		e->color->g = 0;
		e->color->b = 0;
	}
}

static void	key_hook_trans_zoom(int keycode, t_env *e)
{
	if (keycode == 123 || keycode == 124)
		e->tx = keycode == 124 ? e->tx + 0.1 * WIN_X : e->tx - 0.1 * WIN_X;
	else if (keycode == 125 || keycode == 126)
		e->ty = keycode == 125 ? e->ty + 0.1 * WIN_Y : e->ty - 0.1 * WIN_Y;
	else if ((keycode == 78 && e->zoom > 10) || keycode == 69)
		e->zoom = keycode == 78 ? e->zoom / 1.2 : e->zoom * 1.2;
}

static void	key_hook_select(int keycode, t_env *e)
{
	if (keycode == 84)
	{
		e->id_f = 1;
		e->re_c = 0.285;
		e->im_c = 0.52;
	}
	else
	{
		e->id_f = keycode == 83 ? 0 : 2;
		e->ty = keycode == 83 ? e->ty : e->ty + 0.2 * WIN_Y;
		e->re_c = 0;
		e->im_c = 0;
	}
}

int			key_hook(int keycode, t_env *e)
{
	printf("keycode %i\n", keycode);
	if (keycode == 69 || keycode == 78 || keycode >= 123)
		key_hook_trans_zoom(keycode, e);
	else if (keycode == 82)
	{
		e->zoom = ZOOM_INIT;
		e->tx = 0;
		e->ty = 0;
	}
	else if (keycode < 20)
		key_hook_color(keycode, e);
	else if (keycode == 37)
		e->block = 1 - e->block;
	else if (keycode == 83 || keycode == 84 || keycode == 85)
		key_hook_select(keycode, e);
	else if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode != 269)
		clear_and_draw(e);
	return (1);
}
