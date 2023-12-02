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
# include <limits.h>


# define ERROR			1
# define SUCCESS 		0
# define X_WIDTH 		1920
# define Y_HEIGHT		1080
# define SCROLL_UP 		4
# define SCROLL_DOWN 	5

# define MAX_ITERATION 	250
# define MIN_R			-2.0
# define MIN_I			-2.0
# define MAX_R			2.0
# define MAX_I			2.0

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
	E_ERR,
    JULIA,
    MANDEL,
    SHIP
}e_f_choice;


typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

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

typedef struct s_calc
{
	long		ite;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	int			size_x;
	int			size_y;

}t_calc;

typedef struct s_data 
{
	t_lib		lib;
	t_calc		calc;

}				t_data;



//DRAWING
int 	paint_background(t_lib img);
void 	drawCircle(int screen_width, int screen_height, int radius, t_lib img);
void	my_mlx_pixel_put(t_lib *data, int x, int y, int color);

// USERINPUTS
int		mouse_events(int event, int x, int y, t_data *data);
int		keyboard_events(int keycode, t_data *data);
void	clean_exit(t_data *all_data, const char *error_msg);


// INITS
void		init_lib_mlx(t_data *all_data);
t_complex	init_complex(double real, double imaginary);
void		init_calc(t_calc *calc);

// REFRESH
int			refresh(t_data *all_data);

// CALCULATIONS
int			calc_julia(t_data *all_data);
void		pixel_fix(t_lib *lib, int color, int index);

#endif
