/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 23:10:32 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 23:34:48 by mhaziza          ###   ########.fr       */
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

void			ft_display_comments(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0,
		ft_get_color(255, 255, 255), "ESC    = exit");
	mlx_string_put(e->mlx, e->win, 10, 15,
		ft_get_color(255, 255, 255), "- +    = zoom (or scrolling)");
	mlx_string_put(e->mlx, e->win, 10, 30,
		ft_get_color(255, 255, 255), "< >    = horiz tr");
	mlx_string_put(e->mlx, e->win, 10, 45,
		ft_get_color(255, 255, 255), "^ v    = vertic tr");
	mlx_string_put(e->mlx, e->win, 10, 60,
		ft_get_color(255, 255, 255), "R G B  = color management");
	mlx_string_put(e->mlx, e->win, 10, 75,
		ft_get_color(255, 255, 255), "T Z    = all/no color");
	mlx_string_put(e->mlx, e->win, 10, 90,
		ft_get_color(255, 255, 255), "0      = init image");
	mlx_string_put(e->mlx, e->win, 10, 105,
		ft_get_color(255, 255, 255), "L      = Lock Julia's cste");
	mlx_string_put(e->mlx, e->win, 10, 120,
		ft_get_color(255, 255, 255), "1 2 3  = Mandelbrot/Julia/Burningship");
}

int				display_cmds(void)
{
	ft_putstr_fd("Usage : ./fractol <id>\n", 2);
	ft_putstr_fd("-----------------------------\n", 2);
	ft_putstr_fd("  MANDELBROT          id  1\n", 2);
	ft_putstr_fd("  JULIA               id  2\n", 2);
	ft_putstr_fd("  BURNINGSHIP         id  3\n", 2);
	ft_putstr_fd("-----------------------------\n", 2);
	return (0);
}
