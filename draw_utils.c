/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:22:00 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/23 11:20:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	*set_colors(t_env *e, int is_out)
{
	t_color	colors;
	t_color *ptr;

	if (is_out)
	{
		colors.r = 20 + (255 + e->color->r * 10) / e->iter * is_out;
		colors.g = 20 + (255 + e->color->g * 10) / e->iter * is_out;
		colors.b = 20 + (255 + e->color->b * 10) / e->iter * is_out;
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
