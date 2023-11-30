/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:35:39 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/27 22:35:41 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	{
		//perror("SysErrMsg: \n");
		ft_printf("\nMyErrMsg: %s\n", error_msg);
	}
	else
		ft_printf("\n Wopaa BYE BYE :-)!\n\n");
	exit(0);
}

void calculate_julia(t_data *fractal, double cx, double cy)
{
 int  i;
 double tmp;

 fractal->cx = cx;
 fractal->cy = cy;
 fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
 fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
 i = 0;
 while (++i < fractal->max_iterations)
 {
  tmp = fractal->zx;
  fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
     % 255)));
}


int draw_fractal(t_data *all_data, char *query, double cx, double cy)
{
 all_data->x = 0;
 all_data->y = 0;
 while (all_data->x < X_WIDTH)
 {
  while (all_data->y < Y_HEIGHT)
  {
   if (all_data->lib.fractol == MANDEL)
    calculate_mandelbrot(all_data);
   else if (ft_strncmp(query, "julia", 6) == 0)
    calculate_julia(all_data, cx, cy);
   else if (ft_strncmp(query, "ship", 5) == 0)
    calculate_burning_ship(all_data);
   else
   {
    ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
    exit_fractal(all_data);
   }
   all_data->y++;
  }
  all_data->x++;
  all_data->y = 0;
 }
 mlx_put_image_to_window(all_data->lib.mlx, all_data->lib.win, all_data->lib.img, 0, 0);
 return (0);
}









void	render_fractal(t_data *all_data)
{
	if (!(all_data->lib.img = mlx_new_image(all_data->lib.mlx, X_WIDTH, Y_HEIGHT)))
		clean_exit(all_data, "Error Render Creating Image!");
	all_data->lib.addr = mlx_get_data_addr(all_data->lib.img, &all_data->lib.bits_per_pixel, \
	&all_data->lib.line_length, &all_data->lib.endian);
	if (!all_data)
		clean_exit(all_data, "Error Render Saving Data!");
	


	// PUT X AND Y TO THE STRUCT AND HANDLE THEM WITH THE JULIA etc..
	// THEN PUT IMG TO WINDOW 


	if (all_data->lib.fractol == JULIA)
		handleJulia(all_data);
	else if (all_data->lib.fractol == MANDEL)
		handleMandel(all_data);
	else if (all_data->lib.fractol == SHIP)
		handleShipp(all_data);


}

	// TESTING
	//paint_background( all_data->lib);
	//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);
	//drawCircle(X_WIDTH, Y_HEIGHT, 100, all_data->lib);