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
	{
		//perror("SysErrMsg: \n");
		ft_printf("\nMyErrMsg: %s\n", error_msg);
	}
	else
		ft_printf("\n Wopaa BYE BYE :-)!\n\n");
	exit(0);
}

void	render_fractal(t_data *all_data)
{
	if (!(all_data->lib.img = mlx_new_image(all_data->lib.mlx, X_WIDTH, Y_HEIGHT)))
		clean_exit(all_data, "Error Render Creating Image!");
	all_data->lib.addr = mlx_get_data_addr(all_data->lib.img, &all_data->lib.bits_per_pixel, \
	&all_data->lib.line_length, &all_data->lib.endian);
	if (!all_data)
		clean_exit(all_data, "Error Render Saving Data!");
	


	// PUT X AND Y TO THE STRUCT AND HANDLE THEM WITH THE JULIA etc..
	// THEN PUT IMG TO WINDOW 

	/*
	if (all_data->lib.fractol == JULIA)
		handleJulia(all_data);
	else if (all_data->lib.fractol == MANDEL)
		handleMandel(all_data);
	else if (all_data->lib.fractol == SHIP)
		handleShipp(all_data);
		*/
	
	
	// TESTING
	paint_background( all_data->lib);
	drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);
	drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);
	
	
	
	mlx_put_image_to_window(all_data->lib.mlx, all_data->lib.win, all_data->lib.img, 0, 0);
}
