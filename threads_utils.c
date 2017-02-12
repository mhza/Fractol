/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:56:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 20:55:27 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static fct		g_frac[] =
{
	mandelbrot,
	julia,
	burnship,
	NULL
};

void	set_data_img(t_env *e, int x, int y)
{
	// printf("set_data_img\n");

	int	i;

	i = y * e->image->size_line + x * 4;
	e->image->data[i] = set_colors(e, g_frac[e->id_f](e, x, y))->r;
	e->image->data[i + 1] = set_colors(e, g_frac[e->id_f](e, x, y))->g;
	e->image->data[i + 2] = set_colors(e, g_frac[e->id_f](e, x, y))->b;
	e->image->data[i + 3] = 0;
}

static void	*set_data_th(void *tmp)
{
	// printf("set_data_th\n");

	int	i;
	int		y;
	int		x;
	t_env	*e;

//printf("set_data_th\n");
	e = tmp;
	x = e->x;
	y = 0;
	while (y < WIN_Y)
	{//printf("while in expose y = %i\n", y);
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
	printf("THREADS\n");
	int			x;
	int			ret;
	pthread_t	th[WIN_X];

	x = -1;
	while (++x < WIN_X)
	{
		e->x = x;
		ret = pthread_create(&(th[x]), NULL, &set_data_th, (void*)e);
	}
	printf("THREADS 2 \n");

	x = -1;
	while (++x < WIN_X)
		ret = pthread_join(th[x], NULL);

		printf("THREADS 3 \n");

	mlx_put_image_to_window(e->mlx, e->win, e->image->ptr, 0, 0);
	return (0);
}

int		ft_expose_fractal(t_env *e)
{
	printf("WITHOUT_THREADS\n");
	int		x;
	int		y;
	int		is_out;

	x = -1;
	is_out = 0;
	while (++x < WIN_X)
	{
		y = -1;
		e->x = x;
		while (++y < WIN_Y)
			set_data_img(e, x, y);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image->ptr, 0, 0);
	return (0);
}
