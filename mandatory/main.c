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

#include "../includes/fractol.h"


//void check_arguments(int ac, char **av, );


int	create_window(t_lib *lib)
{
	lib->mlx = mlx_init();
	if (lib->mlx == NULL)
		return (ERROR);
	lib->win = mlx_new_window(lib->mlx, X_WIDTH, Y_HEIGHT, "Fract-ol");
	if (lib->win == NULL)
	{
		free(lib->mlx);
		return (ERROR);
	}
	return (SUCCESS);
}

int	create_image(t_lib *lib)
{
	lib->img = mlx_new_image(lib->mlx, X_WIDTH, Y_HEIGHT);
	if (lib->img == NULL)
	{
		free(lib->mlx);
		return (ERROR);
	}
	lib->addr = mlx_get_data_addr(lib->img, &lib->bits_per_pixel, \
	&lib->line_length, &lib->endian);
	return (SUCCESS);
}


int	main(int ac, char **av)
{

	t_data	 all_data;

    if (create_window(&all_data.lib) == SUCCESS && \
        create_image(&all_data.lib) ==  SUCCESS)
    {
        int y = 0;
        int x = 0;
       /// mlx_key_hook(all_data.lib.win, keyboard_events, &all_data);
        //mlx_mouse_hook(all_data.lib.win, mouse_events, &all_data);
        paint_background(x, y, all_data.lib);
        drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
        drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data.lib);
        mlx_put_image_to_window(all_data.lib.mlx, all_data.lib.win, all_data.lib.img, 0, 0);
        mlx_loop(all_data.lib.mlx);
    }
	return (ERROR);
}

