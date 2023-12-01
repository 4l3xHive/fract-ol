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

#include "fractol.h"

void my_mlx_pixel_put(t_lib *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int	ft_julia(t_data *all_data)
{
	t_complex	z;
	int			i;

	z.r = all_data->c.r;
	z.i = all_data->c.i;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < all_data->ite)
	{
		z = ft_init_complex(z.r * z.r - z.i * z.i + all_data->k.r,
				2 * z.r * z.i + all_data->k.i);
		i++;
	}
	return (ft_red_to_black(ft_ints_to_int(
				255 - 255 * ((all_data->ite - i) * (all_data->ite - i))
				% (all_data->ite * all_data->ite), 0, 0)));
}