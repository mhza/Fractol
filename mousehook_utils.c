/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/11 23:09:39 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook(int button, int x, int y, t_env *e)
{
	if (button)
		ft_putnbr(button);

	if (button == 1)
	{
		e->tx = x - e->zoom * 1.71;
		e->ty = y - e->zoom * 1.33;
		// dapres formule : tx = (x1 - re_c) * zoom + x
	}
	else if (button == 4)
	{
		e->zoom *= 0.8;
		e->tx = x - e->zoom * 1.71;
		e->ty = y - e->zoom * 1.33;
	}
	else if (button == 5)
	{
		e->zoom *= 1.2;
		e->tx = x - e->zoom * 1.71;
		e->ty = y - e->zoom * 1.33;
	}
	printf("mouse e->tx %i, e->ty %i, x %i, y %i\n",e->tx, e->ty, x, y);
	clear_and_draw(e);
	return (1);
}


int 	mouse_motion(int x, int y, t_env *e)
{//printf("mouse motion\n");
	e->color->r += x/100;
	e->color->g += y/100;
	e->color->b += 90;
	clear_and_draw(e);
	return (1);
}
