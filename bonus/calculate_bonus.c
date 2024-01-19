/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:02:39 by apyykone          #+#    #+#             */
/*   Updated: 2024/01/11 15:02:40 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	depth_color = ((data->calc.ite - i) * (data->calc.ite - i));
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
	depth_color = ((data->calc.ite - i) * (data->calc.ite - i));
	return (ft_invert_rgb(ft_rgb_to_int(depth_color, depth_color,
				depth_color)));
}

/* inverted mandelbrot */
int	ft_calc_tricorn(t_data *data)
{
	int			i;
	t_complex	c;
	double		tmp;
	int			depth_color;

	c.r = data->calc.c.r;
	c.i = data->calc.c.i;
	i = 0;
	while (i < data->calc.ite)
	{
		if ((c.r * c.r + c.i * c.i) > 4.0)
			break ;
		tmp = -2 * c.r * c.i + data->calc.c.i;
		c.r = c.r * c.r - c.i * c.i + data->calc.c.r;
		c.i = tmp;
		i++;
	}
	depth_color = ((data->calc.ite - i) * (data->calc.ite - i));
	return (ft_invert_rgb(ft_rgb_to_int(depth_color, depth_color,
				depth_color)));
}

int	ft_calc_bship(t_data *data)
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
		c.i = -2.0 * fabs(c.r * c.i) + data->calc.c.i;
		c.r = tmp;
		i++;
	}
	depth_color = ((data->calc.ite - i) * (data->calc.ite - i));
	return (ft_invert_rgb(ft_rgb_to_int(depth_color, depth_color,
				depth_color)));
}
