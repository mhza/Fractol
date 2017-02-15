/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:35:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/15 13:54:01 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_new(int current_id)
{
	t_env	e;
	t_img	image;
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	e.color = &color;
	e.id_f = current_id == 2 ? 0 : current_id + 1;
	ft_init_env(&e, &image);
	ft_expose_fractal_th(&e);
	ft_display_comments(&e);
	mlx_hook(e.win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_motion, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
}

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
	{
		e->zoom = keycode == 78 ? e->zoom / 1.2 : e->zoom * 1.2;
		e->iter = keycode == 78 ? e->iter - 10 : e->iter + 10;
		e->tx -= 0.1 * WIN_X;
		e->ty -= 0.1 * WIN_Y;
	}
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
	else if (keycode == 45)
		key_new(e->id_f);
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
