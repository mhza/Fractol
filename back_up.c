

void	set_data_img(t_env *e, int x, int y)
{
	// printf("set_data_img\n");

	int	i;

	i = y * e->image->size_line + x * 4;
	e->image->data[i] = set_colors(e, g_frac[e->id_f](e, x, y))->r;
	e->image->data[i + 1] = set_colors(e, g_frac[e->id_f](e, x, y))->g;
	e->image->data[i + 2] = set_colors(e, g_frac[e->id_f](e, x, y))->b;
	e->image->data[i + 3] = 0;
}


int		ft_expose_fractal(t_env *e)
{
	printf("WITHOUT_THREADS\n");
	int		x;
	int		y;
	int		is_out;

	x = -1;
	is_out = 0;
	while (++x < WIN_X)
	{
		y = -1;
		e->x = x;
		while (++y < WIN_Y)
			set_data_img(e, x, y);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image->ptr, 0, 0);
	return (0);
}
