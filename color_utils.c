/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:22:00 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/12 13:00:57 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

a = (x + e->tx) - X1


// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) = e->color->r * sqrt(a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 1) = e->color->g * sqrt(a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 2) = e->color->b * sqrt(a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) = e->color->r * (a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 1) = e->color->g * (a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 2) = e->color->b * (a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) =  sqrt(a * a + b * b);
// 	*(image->data + y * image->size_line + x * 4 + 1) =  sqrt(a * a + b * b);
// 	*(image->data + y * image->size_line + x * 4 + 2) =  sqrt(a * a + b * b);
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) = e->color->r * 2 * is_out + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 1) = e->color->g * 2 * is_out + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 2) = e->color->b * 2 * is_out + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
if ((is_out = ft_is_out(e, x, y, image)))
{
	*(image->data + y * image->size_line + x * 4) = (255 + e->color->r * 10) / ITER_MAX * is_out;
	*(image->data + y * image->size_line + x * 4 + 1) = (255 + e->color->g * 10) / ITER_MAX * is_out;
	*(image->data + y * image->size_line + x * 4 + 2) = (255 + e->color->b * 10) / ITER_MAX * is_out;
	*(image->data + y * image->size_line + x * 4 + 3) = 0;
}
else
{
	*(image->data + y * image->size_line + x * 4) = 0;
	*(image->data + y * image->size_line + x * 4 + 1) = 0;
	*(image->data + y * image->size_line + x * 4 + 2) = 0;
	*(image->data + y * image->size_line + x * 4 + 3) = 0;
}















//a = (x + e->tx) - X1;


// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) = e->color->r * sqrt(a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 1) = e->color->g * sqrt(a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 2) = e->color->b * sqrt(a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) = e->color->r * (a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 1) = e->color->g * (a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 2) = e->color->b * (a * a + b * b) + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) =  sqrt(a * a + b * b);
// 	*(image->data + y * image->size_line + x * 4 + 1) =  sqrt(a * a + b * b);
// 	*(image->data + y * image->size_line + x * 4 + 2) =  sqrt(a * a + b * b);
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) = e->color->r * 2 * is_out + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 1) = e->color->g * 2 * is_out + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 2) = e->color->b * 2 * is_out + 255 - 255 / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }








// if ((is_out = ft_is_out(e, x, y, image)))
// {
// 	*(image->data + y * image->size_line + x * 4) = (255 + e->color->r * 10) / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 1) = (255 + e->color->g * 10) / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 2) = (255 + e->color->b * 10) / ITER_MAX * is_out;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
// else
// {
// 	*(image->data + y * image->size_line + x * 4) = 0;
// 	*(image->data + y * image->size_line + x * 4 + 1) = 0;
// 	*(image->data + y * image->size_line + x * 4 + 2) = 0;
// 	*(image->data + y * image->size_line + x * 4 + 3) = 0;
// }
