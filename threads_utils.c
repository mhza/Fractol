/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:56:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/21 18:16:31 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fct		g_frac[] =
{
	mandelbrot,
	julia,
	burnship,
	NULL
};

static void	*set_data_th(void *tmp)
{
	int		i;
	int		y;
	int		x;
	t_env	*e;

	e = tmp;
	x = e->xth;
	y = 0;
	while (y < WIN_Y)
	{
		i = y * e->image->size_line + x * 4;
		e->image->data[i] = set_colors(e, g_frac[e->id_f](e, x, y))->r;
		e->image->data[i + 1] = set_colors(e, g_frac[e->id_f](e, x, y))->g;
		e->image->data[i + 2] = set_colors(e, g_frac[e->id_f](e, x, y))->b;
		e->image->data[i + 3] = 0;
		y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

int			ft_expose_fractal_th(t_env *e)
{


	printf("range WIndow X/ zoom %.2f\n", (float)WIN_X/e->zoom);
	printf("range WIndow Y / zoom %.2f\n", (float)WIN_Y/e->zoom);
	int			x;
	int			ret;
	pthread_t	th[WIN_X];

	x = -1;
	while (++x < WIN_X)
	{
		e->xth = x;
		ret = pthread_create(&(th[x]), NULL, &set_data_th, (void*)e);
		pthread_join(th[x], NULL);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image->ptr, 0, 0);
	return (0);
}
