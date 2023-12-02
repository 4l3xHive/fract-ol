/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:25:47 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/30 23:25:49 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_calc(t_calc *calc)
{
	calc->size_x = X_WIDTH;
	calc->size_y = Y_HEIGHT;
	calc->ite = MAX_ITERATION;
	calc->min = init_complex(MIN_R, MIN_I);
	calc->max = init_complex(MAX_R,
			MIN_I + (MAX_R - MIN_R) * calc->size_x / calc->size_y);
	calc->k = init_complex(-0.4, 0.6);
}

t_complex	init_complex(double real, double imaginary)
{
	t_complex	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}

void init_lib_mlx(t_data *all_data)
{
	if (!(all_data->lib.mlx = mlx_init()))
		clean_exit(all_data, "Failed to init mlx!");
	if (!(all_data->lib.img = mlx_new_image(all_data->lib.mlx, X_WIDTH, Y_HEIGHT)))
		clean_exit(all_data, "Error Render Creating Image!");
	all_data->lib.addr = mlx_get_data_addr(all_data->lib.img, &all_data->lib.bits_per_pixel, \
		&all_data->lib.line_length, &all_data->lib.endian);
	if (all_data->lib.addr == NULL)
		clean_exit(all_data, "Error Render Saving Data!");
	if (!(all_data->lib.win = mlx_new_window(all_data->lib.mlx, X_WIDTH, Y_HEIGHT, "Fract-olli")))
		clean_exit(all_data, "Error Creating Window!");
	mlx_key_hook(all_data->lib.win, keyboard_events, &all_data);
	mlx_mouse_hook(all_data->lib.win, mouse_events, &all_data);
}
