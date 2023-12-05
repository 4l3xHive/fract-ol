/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:23:40 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/26 16:23:42 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_interpolate(double min, double max, double inter)
{
	return (min + ((max - min) * inter));
}

// CALLBACKS CHECKER
int keyboard_events(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_clean_exit(data, NULL);
	}
	return (SUCCESS);
}

int	mouse_events(int event, int x, int y, t_data *all_data)
{
	t_complex	mouse;
	double		zoom;
	double		inter;

	printf("HERE %d\n", event);
	if (event == SCROLL_UP || event == SCROLL_DOWN)
	{
		mouse.r = (double)x / (all_data->calc.size_x / (all_data->calc.max.r - all_data->calc.min.r))
			+ all_data->calc.min.r;
		mouse.i = (double)y / (all_data->calc.size_y / (all_data->calc.max.i - all_data->calc.min.i))
			* -1 + all_data->calc.max.i;
		if (event == SCROLL_DOWN)
			zoom = 0.70;
		else
			zoom = 1.30;
		inter = 1.0 / zoom;
		all_data->calc.min.r = ft_interpolate(mouse.r, all_data->calc.min.r, inter);
		all_data->calc.min.i = ft_interpolate(mouse.i, all_data->calc.min.i, inter);
		all_data->calc.max.r = ft_interpolate(mouse.r, all_data->calc.max.r, inter);
		all_data->calc.max.i = ft_interpolate(mouse.i, all_data->calc.max.i, inter);
		ft_refresh(all_data);
	}
	return (SUCCESS);
}