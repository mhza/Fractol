/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:24:24 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/23 11:08:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# define WIN_X 1000
# define WIN_Y 600
# define ZOOM_INIT 200
# define ABSX -0.8
# define ABSY 0
# define X1 -2.5
# define Y1 -1.5
# define X1_DIFF_C -1.71
# define Y1_DIFF_C -1.33
# define ITER_MAX 100
# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L<<6)
# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_cplex
{
	float	re;
	float	im;
}				t_cplex;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	neg;
}				t_color;

typedef	struct	s_img
{
	void	*ptr;
	char	*data;
	int		bbp;
	int		size_line;
	int		endian;
}				t_img;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	*image;
	float	zoom;
	int		iter;
	float	tx;
	float	ty;
	float	xth;
	float	re_zo;
	float	im_zo;
	int		id_f;
	int		block;
	float	re_c;
	float	im_c;
	float	scro_x;
	float	scro_y;
	t_color	*color;

}				t_env;

typedef int(*t_fct)(t_env *e, int x, int y);
int				mandelbrot(t_env *e, int x, int y);
int				julia(t_env *e, int x, int y);
int				burnship(t_env *e, int x, int y);
void			clear_and_draw(t_env *e);
int				ft_expose_fractal_th(t_env *e);
void			ft_display_comments(t_env *e);
int				key_hook(int keycode, t_env *e);
int				loop_hook(t_env *e);
void			ft_init_env(t_env *e, t_img *image);
int				mouse_hook(int button, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);
t_color			*set_colors(t_env *e, int is_out);
int				display_cmds(void);

#endif
