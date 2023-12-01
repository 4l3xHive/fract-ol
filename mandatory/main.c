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
			clean_exit(NULL, "\tWrong argument enter valid program\n\
	[1] julia\n\t[2] mandelbrot\n\t[3] burningship\n");
	if (!ft_strncmp(av[1], "julia", 6))
		all_data->lib.fractol = JULIA;
	else if (!ft_strncmp(av[1], "mandelbrot", 11))
		all_data->lib.fractol = MANDEL;
	else if (!(ft_strncmp(av[1], "burningship", 12)))
		all_data->lib.fractol = SHIP;
	else
		clean_exit(NULL, "\tWrong argument enter valid program\n\
	[1] julia\n\t[2] mandelbrot\n\t[3] burningship\n");
}

void	clean_exit(t_data *all_data, const char *error_msg)
{
	if (all_data)
	{
		if (all_data->lib.img)
			mlx_destroy_image(all_data->lib.mlx, all_data->lib.img);
		if (all_data->lib.win)
			mlx_destroy_window(all_data->lib.mlx, all_data->lib.win);
		if (all_data->lib.mlx)
			free(all_data->lib.mlx);
	}
	if (error_msg)
		ft_printf("\n%s\n", error_msg);
	else
		ft_printf("\n Wopaa BYE BYE :-)!\n\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_data		all_data;

	// INITS
	get_fractol(ac, av, &all_data);
	init_lib_mlx(&all_data);
	init_math(&all_data);

	draw_fractal(&all_data);
	mlx_loop(all_data.lib.mlx);
	return (SUCCESS);
}

 //paint_background( all_data.lib);
 //drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
