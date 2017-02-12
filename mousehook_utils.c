/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 14:55:47 by mhaziza          ###   ########.fr       */
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
	if (e->id_f == 1 && x < WIN_X / 10 && y < WIN_X / 10)
	{
		e->color->r += rand();
		e->color->g += rand();
		e->color->b += rand();
		clear_and_draw(e);
	}
	return (1);
}
