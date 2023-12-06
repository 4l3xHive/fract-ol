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

static int	ft_set_rgb(int color)
{
	int		r;
	int		g;
	int		b;

	r = color & 0xFF;
	g = (color >> 8) & 0xFF;
	b = (color >> 16) & 0xFF;
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;
	return (r | g << 8 | b << 16);
}

int	ft_calc_julia(t_data *data)
{
	t_complex	z;
	int			i;

	z.r = data->calc.c.r;
	z.i = data->calc.c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < data->calc.ite)
	{
		z = ft_init_complex(z.r * z.r - z.i * z.i + data->calc.k.r,
				2 * z.r * z.i + data->calc.k.i);
		i++;
	}
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((data->calc.ite - i) * (data->calc.ite - i))
				% (data->calc.ite * data->calc.ite), 10, 0)));
}

int	ft_calc_mandelbrot(t_data *data)
{
	t_complex	c;
	double		tmp;
	int			i;

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
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((data->calc.ite - i) * (data->calc.ite - i))
				% (data->calc.ite * data->calc.ite), 0, 0)));
}

/* inverted mandelbrot */
int	ft_calc_tricorn(t_data *data)
{
	int			i;
	t_complex	c;
	double		tmp;

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
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((data->calc.ite - i) * (data->calc.ite - i))
				% (data->calc.ite * data->calc.ite), 0, 0)));
}

int	ft_calc_bship(t_data *data)
{
	t_complex	c;
	double		tmp;
	int			i;

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
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((data->calc.ite - i) * (data->calc.ite - i))
				% (data->calc.ite * data->calc.ite), 0, 0)));
}