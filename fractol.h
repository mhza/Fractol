/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:24:24 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/11 20:19:25 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# define WIN_X 1000
# define WIN_Y 800
# define ITER_MAX 100
# define ZOOM_INIT 300


typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

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

	// float	image_x;
	// float	image_y;
}				t_img;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	*image;
	float		zoom;
	int		tx;
	int		ty;
	float		x;
	float		y;
	int		re_zo;
	int		im_zo;
	float	re_c;
	float	im_c;
	t_color	*color;
}				t_env;

int				ft_expose_fractal(t_env *e);
void			ft_display_comments(t_env *e);
int				key_hook(int keycode, t_env *e);
int					loop_hook(t_env *e);
void			ft_init_env(t_env *e, t_img *image);
int				mouse_hook(int button, int x, int y, t_env *e);




#endif
