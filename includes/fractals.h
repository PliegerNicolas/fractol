/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:46:05 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 01:47:07 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTALS_H
# define FRACTALS_H

/* ************************************** */
/* * INCLUDES							* */
/* ************************************** */

/* ************************************** */
/* * TYPEDEFS							* */
/* ************************************** */

// On modification, update methods in "srcs/utils/fractals.c"
enum e_fractals
{
	mandelbrot = 1,
	julia = 2,
	burning_ship = 3,
	tricorn = 4
};

# define TITLE "fract-ol"
# define DISPLAY_LENGTH 960
# define DISPLAY_WIDTH 540

# define DEFAULT_MAX_ITERATIONS 16

/* Colors */

typedef struct s_trgb
{
	int		transparency;
	int		red;
	int		green;
	int		blue;
	int		center;
	int		width;
	float	red_freq;
	float	green_freq;
	float	blue_freq;
	float	red_phase;
	float	green_phase;
	float	blue_phase;
	float	shift;	
}	t_trgb;

/* Cursor position */
typedef struct s_cursor
{
	int		x;
	int		y;
}	t_cursor;

/* Data structure to hold imaginary number */
typedef struct s_complex
{
	double				real;
	double				imag;
}	t_complex;

/* Vars for display */
typedef struct s_vars
{
	enum e_fractals		selected_fractal;
	void				*img;
	int					max_iterations;
	t_trgb				color;
	t_cursor			cursor_pos;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}	t_vars;

/* viewport related data */
typedef struct s_viewport
{
	struct s_complex	initial_border;
	struct s_complex	initial_center;
	struct s_complex	initial_step;
	struct s_complex	center;
	struct s_complex	border;
	struct s_complex	step;
	double				screen_ratio;
	double				zoom;
	double				zoom_elasticity;
}	t_viewport;

/* mlx data (or display related data) */
typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_vars		vars;
	struct s_viewport	viewport;
}	t_mlx;

/* ************************************** */
/* * FUNCTIONS							* */
/* ************************************** */

/* utils */

char			*select_fractal_index(char *arg);
void			put_available_fractals(int fd);
char			*get_fractal_name_capitalized(enum e_fractals fractal);

#endif
