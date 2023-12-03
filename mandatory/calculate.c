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

static int ft_set_rgb(int color)
{
    int r, g, b;

    r = color & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color >> 16) & 0xFF;
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
    return (r | g << 8 | b << 16);
}

int	ft_calc_julia(t_data *all_data)
{
	t_complex	z;
	int			i;

	z.r = all_data->calc.c.r;
	z.i = all_data->calc.c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < all_data->calc.ite)
	{
		z = ft_init_complex(z.r * z.r - z.i * z.i + all_data->calc.k.r,
				2 * z.r * z.i + all_data->calc.k.i);
		i++;
	}
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((all_data->calc.ite - i) * (all_data->calc.ite - i))
				% (all_data->calc.ite * all_data->calc.ite), 10, 0)));
}

int	ft_calc_mandelbrot(t_data *all_data)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.r = all_data->calc.c.r;
	c.i = all_data->calc.c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i < 4 && i < all_data->calc.ite)
	{
		tmp = c.r * c.r - c.i * c.i + all_data->calc.c.r;
		c.i = 2 * c.r * c.i + all_data->calc.c.i;
		c.r = tmp;
		i++;
	}
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((all_data->calc.ite - i) * (all_data->calc.ite - i))
				% (all_data->calc.ite * all_data->calc.ite), 0, 0)));
}

// SAME AS MANDELBROT BUT -2
int	ft_calc_tricorn(t_data *all_data)
{
	int		i;
	t_complex	c;
	double	tmp;

	c.r = all_data->calc.c.r;
	c.i = all_data->calc.c.i;
	i = 0;
	while (i < all_data->calc.ite)
	{
		if ((c.r * c.r + c.i * c.i) > 4.0)
			break ;
		tmp = -2 * c.r * c.i + all_data->calc.c.i;
		c.r = c.r * c.r - c.i * c.i + all_data->calc.c.r;
		c.i = tmp;
		i++;
	}
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((all_data->calc.ite - i) * (all_data->calc.ite - i))
				% (all_data->calc.ite * all_data->calc.ite), 0, 0)));
}

int	ft_calc_bship(t_data *all_data)
{
	t_complex	c;
	double		tmp;
	int			i;

	c.r = all_data->calc.c.r;
	c.i = all_data->calc.c.i;
	i = 0;
	while (c.r * c.r + c.i * c.i < 4 && i < all_data->calc.ite)
	{
		tmp = c.r * c.r - c.i * c.i + all_data->calc.c.r;
		c.i = -2.0 * fabs(c.r * c.i) + all_data->calc.c.i;
		c.r = tmp;
		i++;
	}
	return (ft_set_rgb(ft_rgb_to_int(
				255 - 255 * ((all_data->calc.ite - i) * (all_data->calc.ite - i))
				% (all_data->calc.ite * all_data->calc.ite), 0, 0)));
}