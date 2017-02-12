/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:22:00 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 14:46:54 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_colors(t_env *e, int is_out)
{
	t_color	colors;
	t_color *ptr;

	if (is_out)
	{
		colors.r = 50 + (255 + e->color->r * 10) / ITER_MAX * is_out;
		colors.g = (255 + e->color->g * 10) / ITER_MAX * is_out;
		colors.b = 50 + (255 + e->color->b * 10) / ITER_MAX * is_out;
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

void	set_data_img(t_env *e, int is_out, int x, int y)
{
	*(e->image->data + y * e->image->size_line + x * 4) =
		set_colors(e, is_out)->r;
	*(e->image->data + y * e->image->size_line + x * 4 + 1) =
		set_colors(e, is_out)->g;
	*(e->image->data + y * e->image->size_line + x * 4 + 2) =
		set_colors(e, is_out)->b;
	*(e->image->data + y * e->image->size_line + x * 4 + 3) = 0;
}
