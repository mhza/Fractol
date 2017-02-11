/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:56:17 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/11 20:12:59 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_is_out(t_env *e, float x, float y, t_img	*image)
{
	float	re_z;
	float	im_z;
	float	re_c;
	float	im_c;
	float	mod;
	float	tmp;
	int		i;

	i = 0;
	re_z = e->re_zo;
	im_z = e->im_zo;
	re_c = (x - e->tx) / e->zoom + image->x1;
	im_c = (y - e->ty) / e->zoom + image->y1;
	mod = 0;
	while (i < ITER_MAX && mod < 4)
	{
		tmp = re_z;
		re_z = re_z * re_z - im_z * im_z + re_c;
		im_z = 2 * tmp * im_z + im_c;
		mod = re_z * re_z + im_z * im_z;
		i++;
	}
	if (i == ITER_MAX)
		return (0);
	return (i);
}

int		ft_expose_fractal(t_env *e)
{
	int		x;
	int		y;
	int		is_out;
	t_img	*image;

	image = e->image;
	// image->x1 = -2.1;
	// image->x2 = 0.6;
	// image->y1 = -1.2;
	// image->y2 = 1.2;
	// image->image_x = (image->x2 - image->x1) * e->zoom;
	// image->image_y = (image->y2 - image->y1) * e->zoom;
	x = 0;
	is_out = 0;
	while (x < WIN_X)
	{
		y = 0;
		while (y < WIN_Y)
		{
			if ((is_out = ft_is_out(e, x, y, image)))
			{
				*(image->data + y * image->size_line + x * 4) = 50 + (255 + e->color->r * 10) / ITER_MAX * is_out;
				*(image->data + y * image->size_line + x * 4 + 1) = (255 + e->color->g * 10) / ITER_MAX * is_out;
				*(image->data + y * image->size_line + x * 4 + 2) = 50 + (255 + e->color->b * 10) / ITER_MAX * is_out;
				*(image->data + y * image->size_line + x * 4 + 3) = 0;
			}
			else
			{
				*(image->data + y * image->size_line + x * 4) = 0;
				*(image->data + y * image->size_line + x * 4 + 1) = 0;
				*(image->data + y * image->size_line + x * 4 + 2) = 0;
				*(image->data + y * image->size_line + x * 4 + 3) = 0;
			}
			y += 1;
		}
		x += 1;
	}
	mlx_put_image_to_window(e->mlx, e->win, image->ptr, 0, 0);
	return (0);
}
