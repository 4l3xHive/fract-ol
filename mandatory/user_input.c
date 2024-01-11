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

/* Keyboard callbacks */
int	keyboard_events(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_clean_exit(data, NULL);
	ft_refresh(data);
	return (SUCCESS);
}

/* Mouse callbacks */
int	mouse_events(int event, int x, int y, t_data *data)
{
	double		zoom;
	double		inter;
	(void )x;
	(void )y;

	if (event == SCROLL_UP || event == SCROLL_DOWN)
	{
		if (event == SCROLL_DOWN)
			zoom = 0.70;
		else
			zoom = 1.30;
		inter = 1.0 / zoom;
		data->calc.min.r *= zoom;
		data->calc.min.i *= zoom;
		data->calc.max.r *= zoom;
		data->calc.max.i *= zoom;
		ft_refresh(data);
	}
	return (SUCCESS);
}