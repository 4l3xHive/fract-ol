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

static void	launch_fractol(t_data *all_data, int index)
{	
	if (all_data->lib.fractol == JULIA)
		pixel_fix(&all_data->lib, calc_julia(all_data), index);
	/*else if (all_data->type == MANDEL)
		ft_pixel_fix(all_data->lib.img, ft_mandelbrot(all_data), index);
	else if (all_data->type == SHIP)
		ft_pixel_fix(all_data->img, ft_burning_ship(all_data), index);
	*/
	/*else if (all_data->type == T_JS)
		ft_pixel_fix(all_data->img, ft_julia_s(all_data), index);
			else if (all_data->type == T_MA_SET)
		ft_pixel_fix(all_data->img, ft_ma_set(all_data), index);
	else if (all_data->type == T_MB)
		ft_pixel_fix(all_data->img, ft_mandelbar(all_data), index);
	*/
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
			//printf("HELLO LOOP\n\n");
			all_data->calc.c.r = all_data->calc.min.r + x * all_data->calc.factor.r;
			launch_fractol(all_data, index);
			index += 4;
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	refresh(t_data *all_data)
{
	all_data->calc.factor = init_complex(
			(all_data->calc.max.r - all_data->calc.min.r) / (X_WIDTH - 1),
			(all_data->calc.max.i - all_data->calc.min.i) / (Y_HEIGHT - 1));
	draw_fractal(all_data);
	mlx_put_image_to_window(all_data->lib.mlx, all_data->lib.win, all_data->lib.img, 0, 0);
	return (SUCCESS);
}

// TESTING
//paint_background( all_data->lib);
//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);
//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);