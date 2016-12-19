/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:23:40 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/19 18:54:29 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_is_out(float x, float y)
{
	float re_z;
	float im_z;
	float mod;
	float tmp;
	int i;

	i = 0;
	re_z = 0;
	im_z = 0;
	mod = 0;
	while (i < ITER_MAX && mod < 4)
	{
		tmp = re_z;
		re_z = re_z * re_z - im_z * im_z + x;
		im_z = 2 * tmp * im_z + y;
		mod = re_z * re_z + im_z * im_z;
		i++;
	}
	if (i == ITER_MAX)
		return (0);
	return (i);
}

int		ft_expose_fractal(t_env *e)
{
	int	x;
	int	y;
	int		is_out;
	t_img	*image;

	image = e->image;

	image->x1 = -2.1;
	image->x2 = 0.6;
	image->y1 = -1.2;
	image->y2 = 1.2;
	image->image_x = (image->x2 - image->x1) * e->zoom;
	image->image_y = (image->y2 - image->y1) * e->zoom;
	x = 0;
	y = 0;
	is_out = 0;
	while (x < image->image_x)
	{
		while (y < image->image_y)
		{
			if ((is_out = ft_is_out((float)x / e->zoom + image->x1,
			(float)y / e->zoom + image->y1)))
			{
				*(image->data + y * image->size_line + x * 4) = 255;
				*(image->data + y * image->size_line + x * 4 + 1) = 255 - 10 * is_out;
				*(image->data + y * image->size_line + x * 4 + 2) = 255;
				*(image->data + y * image->size_line + x * 4 + 3) = 0;
			}
			y += 1;
		}
		y = 0;
		x += 1;
	}
	mlx_put_image_to_window(e->mlx, e->win, image->ptr, e->th, e->tv);
	return (0);
}

void	ft_init_env(t_env *e, t_img *image)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fractol42");
	e->zoom = 100;
	e->th = 10;
	e->tv = 50;
	image->ptr = mlx_new_image(e->mlx, 300, 300);
	image->data = mlx_get_data_addr(image->ptr, &image->bbp,
		&image->size_line, &image->endian);
	e->image = image;
}

int		main(void)
{
	t_env	*e;
	t_img	*image;

	if ((e = (t_env*)ft_memalloc(sizeof(t_env))) == NULL)
		return (0);
	if ((image = (t_img*)ft_memalloc(sizeof(t_img))) == NULL)
		return (0);
	ft_init_env(e, image);
	ft_expose_fractal(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e);
	return (0);
}
