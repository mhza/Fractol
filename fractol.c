/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:23:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 15:26:46 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_and_draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_display_comments(e);
	e->image->data = mlx_get_data_addr(e->image->ptr, &e->image->bbp,
		&e->image->size_line, &e->image->endian);
	ft_expose_fractal_th(e);
	ft_display_comments(e);
	loop_hook(e);
}

void	ft_init_env(t_env *e, t_img *image)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "MANDELBROT");
	e->zoom = ZOOM_INIT;
	e->tx = 0;
	e->ty = 0;
	e->x = 1;
	e->y = 1;
	e->re_zo = 0;
	e->im_zo = 0;
	e->re_c = 0;
	e->im_c = 0;
	e->id_f = 1;
	image->ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	image->data = mlx_get_data_addr(image->ptr, &image->bbp,
		&image->size_line, &image->endian);
	e->image = image;
}

int		loop_hook(t_env *e)
{
	ft_expose_fractal(e);
	mlx_loop(e->mlx);
	return (1);
}

int		main(void)
{
	t_env	e;
	t_img	image;
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	e.color = &color;
	// ft_expose_fractal_th(NULL);
	ft_init_env(&e, &image);
	ft_expose_fractal(&e);
	ft_display_comments(&e);
	mlx_hook(e.win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_motion, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
