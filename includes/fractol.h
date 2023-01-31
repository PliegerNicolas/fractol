/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:52:51 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 01:48:54 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

/* ************************************** */
/* * INCLUDES							* */
/* ************************************** */

# include <mlx.h>
# include <X11/keysym.h>
# include "fractals.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

/* ************************************** */
/* * TYPEDEFS							* */
/* ************************************** */

# define FALSE 0
# define TRUE 1

typedef int	t_bool;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* ************************************** */
/* * COLORS								* */
/* ************************************** */

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"

/* ************************************** */
/* * FUNCTIONS							* */
/* ************************************** */

/* Args verification */

t_bool			verify_args(int argc, char **argv, enum e_fractals *target);
t_bool			error_no_given_arg(int argc);
t_bool			error_excess_given_args(int argc);
t_bool			error_indication(void);
t_bool			error_unrecognized_fractal_name(char *arg);
t_bool			check_if_valid_int(long long int llint);

/* Utils */

int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putendl_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);

void			set_write_color_red(int fd);
void			set_write_color_green(int fd);
void			set_write_color_cyan(int fd);
void			reset_write_color(int fd);

long long int	ft_atolli(const char *nptr);

int				ft_strcmp(char *s1, char *s2);
t_bool			ft_str_is_nbr(char *arg);
char			*ft_lower_str(char *str);
int				ft_tolower(int c);

void			usage_indications(void);

/* Hooks */

void			test_keycode(t_mlx *mlx);

void			set_hooks(t_mlx	*mlx);
void			select_fractal(t_mlx *mlx, enum e_fractals target);
int				hook_numbers(int keycode, t_mlx *mlx);
int				hook_arrows(int keycode, t_mlx *mlx);
int				hook_iterations(int keycode, t_mlx *mlx);
int				hook_mouse(int keycode, int x, int y, t_mlx *mlx);
int				hook_zoom(int keycode, t_mlx *mlx);
int				hook_colorshift(int keycode, t_trgb *color);

int				cursor_move(int x, int y, t_mlx *mlx);
void			set_zoom(t_viewport *viewport);

/* Draw */

void			fill_display(t_mlx *mlx);
void			draw_mandelbrot(t_mlx *mlx, int x, int y);
void			draw_julia(t_mlx *mlx, int x, int y);
void			draw_burning_ship(t_mlx *mlx, int x, int y);
void			draw_tricorn(t_mlx *mlx, int x, int y);

void			init_mandelbrot_algo(t_viewport *viewport);
void			init_julia_algo(t_viewport *viewport);
void			init_burning_ship_algo(t_viewport *viewport);
void			init_tricorn_algo(t_viewport *viewport);

void			set_pixel(t_mlx *mlx, int iterations, int pixel_x, int pixel_y);
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

#endif
