/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:03:42 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/26 16:03:44 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_invert_rgb(int color)
{
	return (~color);
}

int	ft_calc_julia(t_data *data)
{
	t_complex	z;
	int			i;
	int			depth_color;

	z.r = data->calc.c.r;
	z.i = data->calc.c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < data->calc.ite)
	{
		z = ft_init_complex(z.r * z.r - z.i * z.i + data->calc.k.r, 2 * z.r
				* z.i + data->calc.k.i);
		i++;
	}
	depth_color = ((data->calc.ite - i) * (data->calc.ite - i))
		% (data->calc.ite * data->calc.ite);
	return (ft_invert_rgb(ft_rgb_to_int(depth_color, depth_color,
				depth_color)));
}

int	ft_calc_mandelbrot(t_data *data)
{
	t_complex	c;
	double		tmp;
	int			i;
	int			depth_color;

	c.r = data->calc.c.r;
	c.i = data->calc.c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i < 4 && i < data->calc.ite)
	{
		tmp = c.r * c.r - c.i * c.i + data->calc.c.r;
		c.i = 2 * c.r * c.i + data->calc.c.i;
		c.r = tmp;
		i++;
	}
	depth_color = ((data->calc.ite - i) * (data->calc.ite - i))
		% (data->calc.ite * data->calc.ite);
	return (ft_invert_rgb(ft_rgb_to_int(depth_color, depth_color,
				depth_color)));
}
