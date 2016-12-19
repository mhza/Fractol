/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:24:24 by mhaziza           #+#    #+#             */
/*   Updated: 2016/12/19 18:29:18 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# define WIN_X 500
# define WIN_Y 500
# define ITER_MAX 50

typedef	struct	s_img
{
	void	*ptr;
	char	*data;
	int		bbp;
	int		size_line;
	int		endian;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	image_x;
	float	image_y;
}				t_img;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	*image;
	int		zoom;
	int		tv;
	int		th;
}				t_env;

int		ft_expose_fractal(t_env *e);
void	ft_display_comments(t_env *e);
int		key_hook(int keycode, t_env *e);

#endif
