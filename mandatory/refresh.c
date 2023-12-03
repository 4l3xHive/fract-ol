/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:35:39 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/27 22:35:41 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// ALL COLOR CHANNELS (R G B A)
static void	ft_extract_rgb(t_lib *lib, int color, int index)
{
	lib->addr[index] = color >> 16 & 0xFF;
	lib->addr[index + 1] = color >> 8 & 0xFF;
	lib->addr[index + 2] = color & 0xFF;
	lib->addr[index + 3] = 0;
}

static void	launch_fractol(t_data *all_data, int index)
{	
	if (all_data->lib.fractol == JULIA)
		ft_extract_rgb(&all_data->lib, ft_calc_julia(all_data), index);
	else if (all_data->lib.fractol == MANDEL)
		ft_extract_rgb(&all_data->lib, ft_calc_mandelbrot(all_data), index);
	else if (all_data->lib.fractol == TRICORN)
		ft_extract_rgb(&all_data->lib, ft_calc_tricorn(all_data), index);
		else if (all_data->lib.fractol == SHIP)
		ft_extract_rgb(&all_data->lib, ft_calc_bship(all_data), index);
}

static int draw_fractal(t_data *all_data)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < Y_HEIGHT)
	{
		all_data->calc.c.i = all_data->calc.max.i - y * all_data->calc.factor.i;
		x = 0;
		while (x < X_WIDTH)
		{
			all_data->calc.c.r = all_data->calc.min.r + x * all_data->calc.factor.r;
			launch_fractol(all_data, index);
			index += 4;
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	ft_refresh(t_data *all_data)
{
	all_data->calc.factor = ft_init_complex(
			(all_data->calc.max.r - all_data->calc.min.r) / (X_WIDTH - 1),
			(all_data->calc.max.i - all_data->calc.min.i) / (Y_HEIGHT - 1));
	draw_fractal(all_data);
	mlx_put_image_to_window(all_data->lib.mlx, all_data->lib.win, all_data->lib.img, 0, 0);
	return (SUCCESS);
}