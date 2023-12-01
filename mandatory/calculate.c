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

void	clean_exit(t_data *all_data, const char *error_msg)
{
	if (all_data)
	{
		if (all_data->lib.img)
			mlx_destroy_image(all_data->lib.mlx, all_data->lib.img);
		if (all_data->lib.win)
			mlx_destroy_window(all_data->lib.mlx, all_data->lib.win);
		if (all_data->lib.mlx)
			free(all_data->lib.mlx);
	}
	if (error_msg)
		ft_printf("\n%s\n", error_msg);
	else
		ft_printf("\n Wopaa BYE BYE :-)!\n\n");
	exit(0);
}

int	ft_ints_to_int(int r, int g, int b)
{
	int	color;

	color = r | g << 8 | b << 16;
	return (color);
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

int	ft_julia(t_data *all_data)
{
	t_complex	z;
	int			i;

	z.r = all_data->c.r;
	z.i = all_data->c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < all_data->ite)
	{
		z = ft_init_complex(z.r * z.r - z.i * z.i + all_data->k.r,
				2 * z.r * z.i + all_data->k.i);
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(
				255 - 255 * ((all_data->ite - i) * (all_data->ite - i))
				% (all_data->ite * all_data->ite), 0, 0)));
}

int draw_fractal(t_data *all_data)
{
	mlx_clear_window(all_data->lib.mlx, all_data->lib.win);
	all_data->x = 0;
	all_data->y = 0;
	while (all_data->x < X_WIDTH)
	{
		all_data->y = 0;
		while (all_data->y < Y_HEIGHT)
		{
			if (all_data->lib.fractol == JULIA)
				calculate_julia(all_data, cx, cy);
				//if (all_data->lib.fractol == MANDEL)
			// calculate_mandelbrot(all_data);
			//else if (all_data->lib.fractol == SHIP)
			//calculate_burning_ship(all_data);
			all_data->y++;
		}
		all_data->x++;
	}
	mlx_put_image_to_window(all_data->lib.mlx, all_data->lib.win, all_data->lib.img, 0, 0);
	return (0);
}

	// TESTING
	//paint_background( all_data->lib);
	//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);
	//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);