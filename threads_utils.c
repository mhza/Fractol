/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 14:56:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 16:38:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static fct		g_fract_rec[] =
{
	julia,
	julia,
	NULL
};

static void	*set_data_th(void *tmp)
{
	int		y;
	int		x;
	t_env	*e;
//printf("set_data_th\n");
	e = tmp;
	x = e->x;
	y = 0;
	while (y < WIN_Y)
	{//printf("while in expose y = %i\n", y);
		*(e->image->data + y * e->image->size_line + x * 4) =
		set_colors(e, g_fract_rec[e->id_f](e, x, y))->r;
		*(e->image->data + y * e->image->size_line + x * 4 + 1) =
		set_colors(e, g_fract_rec[e->id_f](e, x, y))->g;
		*(e->image->data + y * e->image->size_line + x * 4 + 2) =
		set_colors(e, g_fract_rec[e->id_f](e, x, y))->b;
		*(e->image->data + y * e->image->size_line + x * 4 + 3) = 0;
		y++;
	}
	pthread_exit(NULL);
	return (NULL);
}

int			ft_expose_fractal_th(t_env *e)
{
	int			x;
	int			ret;
	pthread_t	*th;

	x = -1;
	if ((th = ft_memalloc(sizeof(pthread_t) * (WIN_X + 1))) == NULL)
		return (-1);
	while (++x < WIN_X)
	{//printf("while in expose x = %i\n", x);
		e->x = x;
		ret = pthread_create(&(th[x]), NULL, &set_data_th, (void*)e);
		if (ret)
			printf("ret != 0    %i\n", ret);
	}
	x = -1;
	while (++x < WIN_X)
	{
		ret = pthread_join(th[x], NULL);
		if (ret)
			printf("ret pthread_join != 0    %i\n", ret);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image->ptr, 0, 0);
	return (0);
}

int		ft_expose_fractal(t_env *e)
{
	int		x;
	int		y;
	int		is_out;

	x = -1;
	is_out = 0;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
			set_data_img(e, g_fract_rec[e->id_f](e, x, y), x, y);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image->ptr, 0, 0);
	return (0);
}
