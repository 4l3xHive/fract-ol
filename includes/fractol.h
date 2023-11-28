/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:11:25 by apyykone          #+#    #+#             */
/*   Updated: 2023/11/26 13:12:49 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libftprintf/mandatory/ft_printf.h"
# include "../libftprintf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

//COLORS
# define WHITE		0xFFFFFF
# define BLUE		0x0000FF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define YELLOW		0xFFFF00
# define PURPLE		0xFF00FF
# define CYAN		0x00FFFF
# define BLACK		0x000000
# define BEIGE		0xF5F5D2
# define PCHARRIE	0x7D0032
# define FRATARDI	0x4B0015


# define ERROR			1
# define SUCCESS 		0
# define X_WIDTH 		1920
# define Y_HEIGHT		1080
# define SCROLL_UP 		4
# define SCROLL_DOWN 	5

#ifdef __linux__
# include "../minilibx-linux/mlx.h"
# define ESC  	65307
# define UP   	65362
# define DOWN 	65364
# define LEFT 	65361
# define RIGHT	65363
#else
# define ESC  	53
# define UP   	126
# define DOWN 	125
# define LEFT 	123
# define RIGHT	124
# include <mlx.h>
#endif

typedef enum
{
    JULIA,
    MANDEL,
    SHIP
}e_f_choice;


// MATH DATA
typedef struct s_math
{
	int		pixel_x; 
	int		pixel_y;
	double	complex_real;
	double	complex_img;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	x_square;
	double	y_square;
	double	number_real;
	double	number_img;
	double	julia_x;
	double	julia_y;
	int		interations;
	int		max_interation;
	void	(*fractal)(struct s_math *math);

}	t_math;

// MINILIBX DATA
typedef struct s_lib
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			fractol;

}				t_lib;


typedef struct s_data
{
	t_lib		lib;
	t_math		math;

}				t_data;



//DRAWING
int 	paint_background(t_lib img);
void 	drawCircle(int screen_width, int screen_height, int radius, t_lib img);
void	my_mlx_pixel_put(t_lib *data, int x, int y, int color);

// USERINPUTS
int		mouse_events(int event, int x, int y, t_data *data);
int		keyboard_events(int keycode, t_data *data);
void	clean_exit(t_data *all_data, const char *error_msg);

//RENDER
void	render_fractal(t_data *all_data);

#endif
