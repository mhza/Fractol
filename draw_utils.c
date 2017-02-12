/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:22:00 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 23:30:54 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_colors(t_env *e, int is_out)
{
	t_color	colors;
	t_color *ptr;

	if (is_out)
	{
		colors.r = 20 + (255 + e->color->r * 10) / ITER_MAX * is_out;
		colors.g = 20 + (255 + e->color->g * 10) / ITER_MAX * is_out;
		colors.b = 20 + (255 + e->color->b * 10) / ITER_MAX * is_out;
		// colors.r = e->color->r + (255 ) / ITER_MAX * is_out;
		// colors.g = e->color->g + (255 ) / ITER_MAX * is_out;
		// colors.b = e->color->b + (255 ) / ITER_MAX * is_out;
	}
	else
	{
		colors.r = 0;
		colors.g = 0;
		colors.b = 0;
	}
	ptr = &colors;
	return (ptr);
}
