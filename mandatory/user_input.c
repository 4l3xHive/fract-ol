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
#include <stdio.h>

int keyboard_events(int keycode, t_data *data)
{
	ft_printf("here i an keyboard \n");
	if (keycode == ESC)
	{
		clean_exit(data);
	}
	return (SUCCESS);
}

int	mouse_events(int event, int x, int y, t_data *data)
{
	ft_printf("here i an mouseeeee \n");
	(void)x;
	(void)y;
	if (event != SCROLL_DOWN && event != SCROLL_UP)
		return (ERROR);
	if (event == SCROLL_UP)
	{
		data->math.x_max *= 1.115;
		data->math.x_min *= 1.115;
		data->math.y_max *= 1.115;
		data->math.y_min *= 1.115;
	}
	else if (event == SCROLL_DOWN)
	{
		data->math.x_max *= 0.885;
		data->math.x_min *= 0.885;
		data->math.y_max *= 0.885;
		data->math.y_min *= 0.885;
	}
	//render_fractal(data);
	return (SUCCESS);
}
