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

/*Default inits for maths */
void	ft_default_calc_init(t_calc *calc)
{
	calc->size_x = X_WIDTH;
	calc->size_y = Y_HEIGHT;
	calc->ite = MAX_ITERATION;
	calc->min = ft_init_complex(MIN_R, MIN_I);
	calc->max = ft_init_complex(MAX_R, MIN_I + (MAX_R - MIN_R) * calc->size_x
			/ calc->size_y);
	calc->k = ft_init_complex(-0.4, 0.6);
}

/*Inits if arguments given*/
void	ft_args_calc_init(int ac, char **av, t_data *all_data)
{
	if (ft_is_num(av[2]) == FALSE)
		ft_clean_exit(all_data, ARGERROR EXTRA_ARGERROR);
	all_data->calc.ite = ft_atol(av[2]);
	if (all_data->calc.ite <= 0)
		all_data->calc.ite = 1;
	if (ac == 4)
		ft_clean_exit(all_data, ARGERROR EXTRA_ARGERROR);
	if (ac >= 5 && (ft_is_double(av[3]) == FALSE
			|| ft_is_double(av[4]) == FALSE))
		ft_clean_exit(all_data, ARGERROR EXTRA_ARGERROR);
	if (ac >= 5)
	{
		all_data->calc.k.r = ft_atof(av[3]);
		all_data->calc.k.i = ft_atof(av[4]);
	}
}

/* Init the complex numbers */
t_complex	ft_init_complex(double real, double imaginary)
{
	t_complex	c;

	c.r = real;
	c.i = imaginary;
	return (c);
}

/* Init the mlx library & callback hooks */
void	ft_init_lib_mlx(t_data *data)
{
	data->lib.mlx = mlx_init();
	if (data->lib.mlx == NULL)
		ft_clean_exit(data, "Failed to init mlx!");
	data->lib.img = mlx_new_image(data->lib.mlx, X_WIDTH, Y_HEIGHT);
	if (data->lib.img == NULL)
		ft_clean_exit(data, "Failed to init mlx!");
	data->lib.addr = mlx_get_data_addr(data->lib.img, &data->lib.bits_per_pxl,
			&data->lib.line_length, &data->lib.endian);
	if (data->lib.addr == NULL)
		ft_clean_exit(data, "Failed to init mlx!");
	data->lib.win = mlx_new_window(data->lib.mlx, X_WIDTH, Y_HEIGHT, "F-O");
	if (data->lib.win == NULL)
		ft_clean_exit(data, "Failed to init mlx!");
	mlx_key_hook(data->lib.win, keyboard_events, data);
	mlx_mouse_hook(data->lib.win, mouse_events, data);
	mlx_hook(data->lib.win, WIN_X_BTN, 0, ft_close_win, data);
}
