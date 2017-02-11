/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:35:53 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/11 20:22:29 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	ft_get_color(unsigned char red, unsigned char green,
	unsigned char blue)
{
	unsigned int color;

	color = (red << 16) + (green << 8) + blue;
	return (color);
}

int				key_hook(int keycode, t_env *e)
{printf("keycode %i\n", keycode);
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
	if (keycode == 82)
		ft_init_env(e, e->image);
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
	mlx_clear_window(e->mlx, e->win);
	// ft_expose_fractal(e);
	// printf("e->zoom  %.2f e->x %.2f e->y %.2f\n",e->zoom, e->x, e->y);
	// printf("e->image->x1  %.2f     e->image->x2 %.2f     e->image->y1 %.2f     e->image->y2 %.2f    \n",e->image->x1,e->image->x2, e->image->y1,e->image->y2);
// printf("e->image->image_x  %.2f     e->image->image_y %.2f    \n\n",e->image->image_x, e->image->image_y);
	ft_display_comments(e);
	e->image->data = mlx_get_data_addr(e->image->ptr, &e->image->bbp,
		&e->image->size_line, &e->image->endian);
	ft_expose_fractal(e);
	ft_display_comments(e);
	loop_hook(e);
	return (1);
}



// int				loop_hook(t_env *e)
// {
// 	mlx_loop(e->mlx);
// 	return (0);
// }

void			ft_display_comments(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0,
		ft_get_color(0, 0, 0), "Quit   = ESC");
	mlx_string_put(e->mlx, e->win, 10, 15,
		ft_get_color(0, 0, 0), "- +    = zoom");
	mlx_string_put(e->mlx, e->win, 10, 30,
		ft_get_color(0, 0, 0), "< >    = horiz tr");
	mlx_string_put(e->mlx, e->win, 10, 45,
		ft_get_color(0, 0, 0), "^ v    = vertic tr");
}
