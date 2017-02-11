/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:32:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/11 22:09:54 by mhaziza          ###   ########.fr       */
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
		e->tx = x - e->zoom * 1.71;
		e->ty = y - e->zoom * 1.33;
	}
	printf("mouse e->tx %i, e->ty %i, x %i, y %i\n",e->tx, e->ty, x, y);

	mlx_clear_window(e->mlx, e->win);
	ft_display_comments(e);
	e->image->data = mlx_get_data_addr(e->image->ptr, &e->image->bbp,
		&e->image->size_line, &e->image->endian);
	ft_expose_fractal(e);
	ft_display_comments(e);
	loop_hook(e);
	return (1);
}


int 	mouse_motion_manager()
{
	return (1);
}
