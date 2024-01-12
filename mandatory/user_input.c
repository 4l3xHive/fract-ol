/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:23:40 by apyykone          #+#    #+#             */
/*   Updated: 2024/01/12 06:26:14 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	double	zoom;

	(void)x;
	(void)y;
	if (event == SCROLL_UP || event == SCROLL_DOWN)
	{
		if (event == SCROLL_DOWN)
			zoom = 0.70;
		else
			zoom = 1.30;
		data->calc.min.r *= zoom;
		data->calc.min.i *= zoom;
		data->calc.max.r *= zoom;
		data->calc.max.i *= zoom;
		ft_refresh(data);
	}
	return (SUCCESS);
}
