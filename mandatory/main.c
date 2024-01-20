/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:16:00 by apyykone          #+#    #+#             */
/*   Updated: 2024/01/03 17:45:52 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * @brief Cleans up the program and exits
 * @param all_data The struct containing all the data
 * @param error_msg The error message to be printed
 */
void	ft_clean_exit(t_data *all_data, const char *error_msg)
{
	if (error_msg)
	{
		ft_putstr_fd((char *)error_msg, 2);
		exit(EXIT_FAILURE);
	}
	if (all_data)
	{
		mlx_destroy_image(all_data->lib.mlx, all_data->lib.img);
		mlx_destroy_window(all_data->lib.mlx, all_data->lib.win);
	}
	ft_printf(CLEAN_EXIT_MSG);
	exit(EXIT_SUCCESS);
}

static void	ft_handle_args(int ac, char **av, t_data *all_data)
{
	if (ac < 2)
		ft_clean_exit(NULL, ARGERROR);
	if (!ft_strncmp(av[1], "julia", 6))
		all_data->lib.fractol = JULIA;
	else if (!ft_strncmp(av[1], "mandelbrot", 11))
		all_data->lib.fractol = MANDEL;
	else
		ft_clean_exit(NULL, ARGERROR EXTRA_ARGERROR);
	ft_default_calc_init(&all_data->calc);
	if (ac > 2)
		ft_extra_args_init(ac, av, all_data);
}

int	main(int ac, char **av)
{
	t_data	all_data;

	ft_memset(&all_data, 0, sizeof(t_data));
	ft_handle_args(ac, av, &all_data);
	ft_init_lib_mlx(&all_data);
	ft_refresh(&all_data);
	mlx_loop(all_data.lib.mlx);
	return (SUCCESS);
}
