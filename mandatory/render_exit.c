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