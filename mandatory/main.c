/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:16:00 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/26 13:16:51 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_clean_exit(t_data *all_data, const char *error_msg)
{
	if (error_msg)
		ft_printf("\n"RED_BUFF"\n\n", error_msg);
	else
		ft_printf("\n\t"GREEN_BUFF"\n\n", "<('') EXITED CLEAN ('')>");
	if (all_data)
	{
		if (all_data->lib.img)
			mlx_destroy_image(all_data->lib.mlx, all_data->lib.img);
		if (all_data->lib.win)
			mlx_destroy_window(all_data->lib.mlx, all_data->lib.win);
		if (all_data->lib.mlx)
			free(all_data->lib.mlx);
	}
	exit(0);
	return (SUCCESS);
}

static void	ft_get_args(int ac, char **av, t_data *all_data)
{
	if (ac < 2)
		ft_clean_exit(NULL, "\tWrong argument enter valid program\n\
	[1] julia\n\t[2] mandelbrot\n\t[3] burningship\n\t[4] tricorn");
	if (!ft_strncmp(av[1], "julia", 6))
		all_data->lib.fractol = JULIA;
	else if (!ft_strncmp(av[1], "mandelbrot", 11))
		all_data->lib.fractol = MANDEL;
	else if (!(ft_strncmp(av[1], "burningship", 12)))
		all_data->lib.fractol = SHIP;
	else if (!(ft_strncmp(av[1], "tricorn", 8)))
		all_data->lib.fractol = TRICORN;
	else 
		ft_clean_exit(NULL, "\tWrong argument enter valid program\n\
	[1] julia\n\t[2] mandelbrot\n\t[3] burningship\n\t[4] tricorn");
	ft_default_calc_init(&all_data->calc);
	if (ac > 2)
		ft_args_calc_init(ac, av, all_data);
}

int	main(int ac, char **av)
{
	t_data		all_data;

	ft_get_args(ac, av, &all_data);
	ft_init_lib_mlx(&all_data);
	ft_refresh(&all_data);
	mlx_loop(all_data.lib.mlx);
	return (SUCCESS);
}
