/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:23:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/23 11:07:23 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_and_draw(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	e->image->data = mlx_get_data_addr(e->image->ptr, &e->image->bbp,
		&e->image->size_line, &e->image->endian);
	ft_expose_fractal_th(e);
	ft_display_comments(e);
	loop_hook(e);
}

void	ft_init_env(t_env *e, t_img *image)
{
	if (e->id_f == 1)
	{
		e->re_c = 0.285;
		e->im_c = 0.52;
	}
	else
	{
		e->re_c = 0;
		e->im_c = 0;
	}
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fract'ol");
	e->zoom = ZOOM_INIT;
	e->iter = ITER_MAX;
	e->tx = -WIN_X / 2;
	e->ty = -WIN_Y / 2;
	e->re_zo = 0;
	e->im_zo = 0;
	e->block = 1;
	image->ptr = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	image->data = mlx_get_data_addr(image->ptr, &image->bbp,
		&image->size_line, &image->endian);
	e->image = image;
}

int		loop_hook(t_env *e)
{
	mlx_loop(e->mlx);
	return (1);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_img	image;
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	e.color = &color;
	if (ac != 2 ||
		(ft_atoi(av[1]) != 1 && ft_atoi(av[1]) != 2 && ft_atoi(av[1]) != 3))
		return (display_cmds());
	else
		e.id_f = ft_atoi(av[1]) - 1;
	ft_init_env(&e, &image);
	ft_expose_fractal_th(&e);
	ft_display_comments(&e);
	mlx_hook(e.win, MOTION_NOTIFY, PTR_MOTION_MASK, mouse_motion, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
