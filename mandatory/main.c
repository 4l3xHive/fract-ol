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

void		get_fractol(int ac, char **av, t_data *all_data)
{
	if (ac > 2 || ac == 1)
			clean_exit(NULL, "Wrong argument enter valid program\n\
	[1] julia\n\t[2] mandelbrot\n\t[3] burningship\n");
	if (!ft_strncmp(av[1], "julia", 6))
		all_data->lib.fractol = JULIA;
	else if (!ft_strncmp(av[1], "mandelbrot", 11))
		all_data->lib.fractol = MANDEL;
	else if (!(ft_strncmp(av[1], "burningship", 12)))
		all_data->lib.fractol = SHIP;
	clean_exit(NULL, "Wrong argument enter valid program\n\
	[1] julia\n\t[2] mandelbrot\n\t[3] burningship\n");
}

int	main(int ac, char **av)
{
	t_data		all_data;

	// INITS
	get_fractol(ac, av, &all_data);
		clean_exit(&all_data, NULL);
	if (!(all_data.lib.mlx = mlx_init()))
		clean_exit(&all_data, "Failed to init mlx!");
	if (!(all_data.lib.win = mlx_new_window(all_data.lib.mlx, X_WIDTH, Y_HEIGHT, "Fract-olli")))
		clean_exit(&all_data, "Error Creating Window!");

	// START THE FRACTAL
	render_fractal(&all_data);
	mlx_key_hook(all_data.lib.win, keyboard_events, &all_data);
	mlx_mouse_hook(all_data.lib.win, mouse_events, &all_data);
	mlx_loop(all_data.lib.mlx);
	return (SUCCESS);
}

 //paint_background( all_data.lib);
 //drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
