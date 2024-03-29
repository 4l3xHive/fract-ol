/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:03:29 by apyykone          #+#    #+#             */
/*   Updated: 2024/01/11 15:03:31 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

/**
 * @brief Extracts all color channels from an int and stores them in the addr
 * @param lib The struct containing the mlx data
 * @param color The color to be extracted
 * @param index The index of the addr
 */
static void	ft_extract_rgb(t_lib *lib, int color, int index)
{
	lib->addr[index] = color >> 16 & 0xFF;
	lib->addr[index + 1] = color >> 8 & 0xFF;
	lib->addr[index + 2] = color & 0xFF;
	lib->addr[index + 3] = 0;
}

static void	launch_fractol(t_data *data, int index)
{
	if (data->lib.fractol == JULIA)
		ft_extract_rgb(&data->lib, ft_calc_julia(data), index);
	else if (data->lib.fractol == MANDEL)
		ft_extract_rgb(&data->lib, ft_calc_mandelbrot(data), index);
	else if (data->lib.fractol == TRICORN)
		ft_extract_rgb(&data->lib, ft_calc_tricorn(data), index);
	else if (data->lib.fractol == SHIP)
		ft_extract_rgb(&data->lib, ft_calc_bship(data), index);
}

static int	draw_fractal(t_data *data)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < Y_HEIGHT)
	{
		data->calc.c.i = data->calc.max.i - y * data->calc.factor.i;
		x = 0;
		while (x < X_WIDTH)
		{
			data->calc.c.r = data->calc.min.r + x * data->calc.factor.r;
			launch_fractol(data, index);
			index += 4;
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

/**
 * @brief Refreshes the window
 * @param data all data
 */
int	ft_refresh(t_data *data)
{
	data->calc.factor = ft_init_complex((data->calc.max.r - data->calc.min.r)
			/ (X_WIDTH - 1), (data->calc.max.i - data->calc.min.i) / (Y_HEIGHT
				- 1));
	draw_fractal(data);
	mlx_put_image_to_window(data->lib.mlx, data->lib.win, data->lib.img, 0, 0);
	return (SUCCESS);
}
