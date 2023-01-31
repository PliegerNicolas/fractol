/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:39:43 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 01:47:30 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	initialize_color(t_trgb *color)
{
	color->width = 128;
	color->center = 127;
	color->red = 0;
	color->green = 0;
	color->blue = 0;
	color->red_freq = 0.33;
	color->green_freq = 0.33;
	color->blue_freq = 0.33;
	color->red_phase = (2 * M_PI) / 3;
	color->green_phase = (4 * M_PI) / 3;
	color->blue_phase = 0.00;
	color->shift = 1.00;
}

void	select_fractal(t_mlx *mlx, enum e_fractals target)
{
	mlx->vars.selected_fractal = target;
	mlx->vars.max_iterations = DEFAULT_MAX_ITERATIONS;
	initialize_color(&mlx->vars.color);
	mlx->viewport.zoom = 1;
	if (target == mandelbrot)
		init_mandelbrot_algo(&mlx->viewport);
	else if (target == julia)
		init_julia_algo(&mlx->viewport);
	else if (target == burning_ship)
		init_burning_ship_algo(&mlx->viewport);
	else if (target == tricorn)
		init_tricorn_algo(&mlx->viewport);
}

int	hook_numbers(int keycode, t_mlx *mlx)
{
	if (keycode == XK_1 || keycode == XK_KP_End)
		select_fractal(mlx, mandelbrot);
	else if (keycode == XK_2 || keycode == XK_KP_Down)
		select_fractal(mlx, julia);
	else if (keycode == XK_3 || keycode == XK_KP_Page_Down)
		select_fractal(mlx, burning_ship);
	else if (keycode == XK_4 || keycode == XK_KP_Left)
		select_fractal(mlx, tricorn);
	else
		return (0);
	return (1);
}
