/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:03:42 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/26 16:03:44 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_lib *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int paint_background(int x, int y, t_lib img){

    while(1) 
    {
        my_mlx_pixel_put(&img, x, y, 0x00FF0000 | 0x000000FF);
        x++;
        if (x >= 1920)
        {
            x = 0;
            y++;
        }
        if (y >= 1080)
            break;
        x++;
    }
return (0);
}

void drawCircle(int screen_width, int screen_height, int radius, t_lib img)
{
    int center_x = screen_width / 2;
    int center_y = screen_height / 2;

    for (int x = 0; x < screen_width; x++) {
        for (int y = 0; y < screen_height; y++) {
            double distance = sqrt(pow(x - center_x, 2) + pow(y - center_y, 2));
            if (fabs(distance - radius) < 0.5) {
                 my_mlx_pixel_put(&img, x, y, 0x0000f0);
            }
        }
    }
}
