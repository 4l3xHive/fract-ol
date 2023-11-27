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

int		get_fractol(int ac, char **av)
{
	if (ac > 2 || ac == 1)
		clean_exit(NULL);
	if (!ft_strncmp(av[1], "julia", 6))
		return (1);
	else if (!ft_strncmp(av[1], "mandelbrot", 11))
		return (2);
	else if (!(ft_strncmp(av[1], "burningship", 12)))
		return (3);
	clean_exit(NULL);
	return (-1);
}

int	main(int ac, char **av)
{
	
	t_data		all_data;
	int			fractol;

	if ((fractol = get_fractol(ac, av)) < 0)
		clean_exit(&all_data);
	init_lib_data(&all_data);
	 paint_background(all_data.lib);
 	drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
	drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
	mlx_put_image_to_window(all_data.lib.mlx, all_data.lib.win, all_data.lib.img, 0, 0);
	mlx_loop(all_data.lib.mlx);
    

	return (ERROR);
}

 //paint_background( all_data.lib);
 //drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
