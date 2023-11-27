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

void	clean_exit(t_data *all_data)
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
	ft_printf("\n Wopaa BYE BYE :-)!\n\n");
	exit(0);
}

void	init_lib_data(t_data *all_data)
{
	if (!(all_data->lib.mlx = mlx_init()))
		clean_exit(all_data);
	if (!(all_data->lib.win = mlx_new_window(all_data->lib.mlx, X_WIDTH, Y_HEIGHT, "Fract-olli")))
		clean_exit(all_data);
	if (!(all_data->lib.img = mlx_new_image(all_data->lib.mlx, X_WIDTH, Y_HEIGHT)))
		clean_exit(all_data);
	all_data->lib.addr = mlx_get_data_addr(all_data->lib.img, &all_data->lib.bits_per_pixel, \
	&all_data->lib.line_length, &all_data->lib.endian);
	if (!all_data)
		clean_exit(all_data);
	mlx_key_hook(all_data->lib.win, keyboard_events, all_data);
	mlx_mouse_hook(all_data->lib.win, mouse_events, all_data);
}

