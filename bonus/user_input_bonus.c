/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:23:40 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/26 16:23:42 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static double	ft_interpolate(double min, double max, double inter)
{
	return (min + ((max - min) * inter));
}

/**
 * @brief Exit the program clean when user press X
 * @param data all data
 */
int	ft_close_win(t_data *data)
{
	ft_clean_exit(data, NULL);
	return (SUCCESS);
}

/**
 * @brief Handles keyboard events
 * @param keycode key pressed
 * @param data all data
 */
int	keyboard_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_clean_exit(data, NULL);
	if (keycode == RIGHT)
	{
		data->calc.min.r += 0.05;
		data->calc.max.r += 0.05;
	}
	else if (keycode == LEFT)
	{
		data->calc.min.r -= 0.05;
		data->calc.max.r -= 0.05;
	}
	else if (keycode == DOWN)
	{
		data->calc.min.i -= 0.05;
		data->calc.max.i -= 0.05;
	}
	else if (keycode == UP)
	{
		data->calc.min.i += 0.05;
		data->calc.max.i += 0.05;
	}
	ft_refresh(data);
	return (SUCCESS);
}

/**
 * @brief Handles mouse events
 * @param event mouse event
 * @param x mouse x position
 * @param y mouse y position
 * @param data all data
 */
int	mouse_events(int event, int x, int y, t_data *data)
{
	t_complex	mouse;
	double		zoom;
	double		inter;

	if (event == SCROLL_UP || event == SCROLL_DOWN)
	{
		mouse.r = (double)x / (data->calc.size_x / (data->calc.max.r
					- data->calc.min.r)) + data->calc.min.r;
		mouse.i = (double)y / (data->calc.size_y / (data->calc.max.i
					- data->calc.min.i)) * -1 + data->calc.max.i;
		if (event == SCROLL_DOWN)
			zoom = 0.70;
		else
			zoom = 1.30;
		inter = 1.0 / zoom;
		data->calc.min.r = ft_interpolate(mouse.r, data->calc.min.r, inter);
		data->calc.min.i = ft_interpolate(mouse.i, data->calc.min.i, inter);
		data->calc.max.r = ft_interpolate(mouse.r, data->calc.max.r, inter);
		data->calc.max.i = ft_interpolate(mouse.i, data->calc.max.i, inter);
		ft_refresh(data);
	}
	return (SUCCESS);
}
