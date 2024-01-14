/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:16:17 by apyykone          #+#    #+#             */
/*   Updated: 2023/12/03 21:16:19 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
 * @brief Converts an rgb 3 int values to a single int
 * @param r The red value
 * @param g The green value
 * @param b The blue value
 */
int	ft_rgb_to_int(int r, int g, int b)
{
	int	color;

	color = r | g << 8 | b << 16;
	return (color);
}

/**
 * @brief Checks if the string is a valid double
 * @param n The string to be checked
 */
int	ft_is_double(const char *n)
{
	unsigned long	i;
	int				p;

	i = 0;
	while (n[i] && (n[i] <= 32))
		i++;
	if (n[i] && (n[i] == '+' || n[i] == '-'))
		i++;
	if (!n[i])
		return (FALSE);
	p = FALSE;
	while (n[i])
	{
		if (!ft_isdigit(n[i]) && n[i] != '.' && n[i] != ',')
			return (FALSE);
		if ((n[i] == '.' || n[i] == ',') && p == TRUE)
			return (FALSE);
		if (n[i] == '.' || n[i] == ',')
			p = TRUE;
		i++;
	}
	return (TRUE);
}

/**
 * @brief Checks if the string is a valid number
 * @param n The string to be checked
 */
int	ft_is_num(const char *n)
{
	unsigned long	i;

	i = 0;
	while (n[i] && n[i] <= 32)
		i++;
	if (n[i] && (n[i] == '+' || n[i] == '-'))
		i++;
	if (!n[i])
		return (FALSE);
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
