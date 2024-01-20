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

# include "libft.h"
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define ARGERROR \
	"\033[0;31m\
	First argument must be valid fractal!\n\
	[1] julia\n\
	[2] mandelbrot\n"
# define EXTRA_ARGERROR \
	"\033[0;31m	./fractol <argv1> fractal <argv2>(int) \
(<argv3>(double) + <argv4>(double)) \033[0m\n"
# define CLEAN_EXIT_MSG "\033[0;32m<('') EXITED CLEAN ('')>\033[0m\n"
# define WIN_X_BTN 17
# define ERROR 1
# define SUCCESS 0
# define TRUE 1
# define FALSE 0
# define X_WIDTH 500
# define Y_HEIGHT 500
# define MAX_ITERATION 250
# define MIN_R -2
# define MIN_I -2
# define MAX_R 2
# define MAX_I 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MINUS 69
# define PLUS 78
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
# else
#  define ESC 53
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  include <mlx.h>
# endif

typedef enum e_choice
{
	E_ERR,
	JULIA,
	MANDEL
}				t_e_choice;

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_lib
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pxl;
	int			line_length;
	int			endian;
	int			fractol;

}				t_lib;

typedef struct s_fractal
{
	long		ite;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	int			size_x;
	int			size_y;

}				t_fractal;

typedef struct s_data
{
	t_lib		lib;
	t_fractal	calc;

}				t_data;

int				mouse_events(int event, int x, int y, t_data *data);
int				keyboard_events(int keycode, t_data *data);
void			ft_clean_exit(t_data *all_data, const char *error_msg);
int				ft_close_win(t_data *data);
void			ft_init_lib_mlx(t_data *all_data);
t_complex		ft_init_complex(double real, double imaginary);
void			ft_default_calc_init(t_fractal *calc);
void			ft_extra_args_init(int ac, char **av, t_data *all_data);
int				ft_refresh(t_data *all_data);
int				ft_calc_julia(t_data *all_data);
int				ft_calc_mandelbrot(t_data *all_data);
int				ft_is_num(const char *str);
int				ft_is_double(const char *n);
int				ft_rgb_to_int(int r, int g, int b);

#endif
