/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:35:53 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/19 18:53:15 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


unsigned int ft_get_color(unsigned char red, unsigned char green, unsigned char blue)
{
	unsigned int color;

	color = (red << 16) + (green << 8) + blue;
	return (color);
}
int		key_hook(int keycode, t_env *e)
{
	if (keycode == 123 || keycode == 124)
		e->th = keycode == 124 ? e->th + WIN_X / 10 : e->th - WIN_X / 10;
	if (keycode == 125 || keycode == 126)
		e->tv = keycode == 125 ? e->tv + WIN_Y / 10 : e->tv - WIN_Y / 10;
	if ((e->zoom > 1 && keycode == 78) || keycode == 69)
		e->zoom = keycode == 78 ? e->zoom / 2 : e->zoom * 2;
	if (keycode == 53)
		exit(0);
	mlx_clear_window(e->mlx, e->win);
	e->image->data = mlx_get_data_addr(e->image->ptr, &e->image->bbp,
		&e->image->size_line, &e->image->endian);
	ft_expose_fractal(e);
	ft_display_comments(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (!e || !button || !x || !y)
		return (0);
	return (0);
}

int		loop_hook(t_env *e)
{
	mlx_loop(e->mlx);
	return (0);
}

void	ft_display_comments(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, ft_get_color(255, 0, 255), "Quit   = ESC");
	mlx_string_put(e->mlx, e->win, 10, 15, ft_get_color(255, 0, 255), "- +    = zoom");
	mlx_string_put(e->mlx, e->win, 10, 30, ft_get_color(255, 0, 255), "< >    = horiz tr");
	mlx_string_put(e->mlx, e->win, 10, 45, ft_get_color(255, 0, 255), "^ v    = vertic tr");
}
