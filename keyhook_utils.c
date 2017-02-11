/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:35:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/11 23:25:22 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode, t_env *e)
{//printf("keycode %i\n", keycode);
	if (keycode == 123 || keycode == 124)
		e->tx = keycode == 124 ? e->tx + 0.1 * WIN_X : e->tx - 0.1 * WIN_X;
	if (keycode == 125 || keycode == 126)
		e->ty = keycode == 125 ? e->ty + 0.1 * WIN_Y : e->ty - 0.1 * WIN_Y;
	if ((keycode == 78 && e->zoom > 10) || keycode == 69)
		e->zoom = keycode == 78 ? e->zoom /1.2 : e->zoom * 1.2;
	if (keycode == 11)
		e->color->r += 10;
	if (keycode == 5)
		e->color->g += 10;
	if (keycode == 15)
		e->color->b += 10;
	// if (keycode == 82)
	// 	ft_init_env(e, e->image);
	if (keycode == 17)
	{
		e->color->r += 10;
		e->color->g += 50;
		e->color->b += 90;
	}
	if (keycode == 6)
	{
		e->color->r = 0;
		e->color->g = 0;
		e->color->b = 0;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	clear_and_draw(e);
	return (1);
}
