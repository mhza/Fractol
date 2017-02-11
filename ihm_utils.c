/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 23:10:32 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/11 23:25:27 by mhaziza          ###   ########.fr       */
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
		ft_get_color(0, 0, 0), "Quit   = ESC");
	mlx_string_put(e->mlx, e->win, 10, 15,
		ft_get_color(0, 0, 0), "- +    = zoom");
	mlx_string_put(e->mlx, e->win, 10, 30,
		ft_get_color(0, 0, 0), "< >    = horiz tr");
	mlx_string_put(e->mlx, e->win, 10, 45,
		ft_get_color(0, 0, 0), "^ v    = vertic tr");
}
