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

void my_mlx_pixel_put(t_lib *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int	ft_red_to_black(int color)
{
	int	r;
	int	g;
	int	b;

	r = color & 0xFF;
	g = color >> 8 & 0xFF;
	b = color >> 16 & 0xFF;
	if (r == 255 && g == 0 && b == 0)
		return (0);
	return (color);
}

int	ft_ints_to_int(int r, int g, int b)
{
	int	color;

	color = r | g << 8 | b << 16;
	return (color);
}

void	ft_pixel(t_lib *lib, int color, int index)
{
	lib->addr[index] = color & 0xFF;
	lib->addr[index + 1] = color >> 8 & 0xFF;
	lib->addr[index + 2] = color >> 16 & 0xFF;
	lib->addr[index + 3] = 0;
}

void	pixel_fix(t_lib *lib, int color, int index)
{
	lib->addr[index] = color >> 16 & 0xFF;
	lib->addr[index + 1] = color >> 8 & 0xFF;
	lib->addr[index + 2] = color & 0xFF;
	lib->addr[index + 3] = 0;
}

int	calc_julia(t_data *all_data)
{
	t_complex	z;
	int			i;

	z.r = all_data->calc.c.r;
	z.i = all_data->calc.c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < all_data->calc.ite)
	{
		z = init_complex(z.r * z.r - z.i * z.i + all_data->calc.k.r,
				2 * z.r * z.i + all_data->calc.k.i);
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(
				255 - 255 * ((all_data->calc.ite - i) * (all_data->calc.ite - i))
				% (all_data->calc.ite * all_data->calc.ite), 0, 0)));
}


