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

void	ft_default_calc_init(t_calc *calc)
{
	calc->size_x = X_WIDTH;
	calc->size_y = Y_HEIGHT;
	calc->ite = MAX_ITERATION;
	calc->min = ft_init_complex(MIN_R, MIN_I);
	calc->max = ft_init_complex(MAX_R,
			MIN_I + (MAX_R - MIN_R) * calc->size_x / calc->size_y);
	calc->k = ft_init_complex(-0.4, 0.6);
}

void	ft_args_calc_init(int ac, char **av, t_data *all_data)
{
	if (ac > 2 && ft_is_num(av[2]) == FALSE)
		ft_clean_exit(all_data, "The second argument must be a valid integer!");
	if (ac > 2)
	{
		all_data->calc.ite = ft_atol(av[2]);
		if (all_data->calc.ite <= 0)
			all_data->calc.ite = 1;
	}
	if (ac >= 5
		&& (ft_is_double(av[3]) == FALSE || ft_is_double(av[4]) == FALSE))
			ft_clean_exit(all_data, "Third or fourth argument is not a number !");
	if (ac >= 5)
	{
		all_data->calc.k.r = ft_atof(av[3]);
		all_data->calc.k.i = ft_atof(av[4]);
	}
}

t_complex	ft_init_complex(double real, double imaginary)
{
	t_complex	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}

void ft_init_lib_mlx(t_data *all_data)
{
	if (!(all_data->lib.mlx = mlx_init()))
		ft_clean_exit(all_data, "Failed to init mlx!");
	if (!(all_data->lib.img = mlx_new_image(all_data->lib.mlx, X_WIDTH, Y_HEIGHT)))
		ft_clean_exit(all_data, "Error Render Creating Image!");
	all_data->lib.addr = mlx_get_data_addr(all_data->lib.img, &all_data->lib.bits_per_pixel, \
		&all_data->lib.line_length, &all_data->lib.endian);
	if (all_data->lib.addr == NULL)
		ft_clean_exit(all_data, "Error Render Saving Data!");
	if (!(all_data->lib.win = mlx_new_window(all_data->lib.mlx, X_WIDTH, Y_HEIGHT, "Fract-olli")))
		ft_clean_exit(all_data, "Error Creating Window!");
	mlx_key_hook(all_data->lib.win, keyboard_events, all_data);
	mlx_mouse_hook(all_data->lib.win, mouse_events, all_data);
	mlx_hook(all_data->lib.win, 33, 1L << 5, ft_clean_exit, all_data);
}
