/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:16:17 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/28 02:10:39 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	init_mandelbrot_algo(t_viewport *viewport)
{
	viewport->screen_ratio = (double)DISPLAY_LENGTH / (double)DISPLAY_WIDTH;
	viewport->border.real = 2.0;
	viewport->border.imag = 1.15;
	viewport->center.real = -0.5;
	viewport->center.imag = 0.0;
	viewport->step.real = ((viewport->center.real + viewport->border.real)
			- (viewport->center.real - viewport->border.real)) / DISPLAY_LENGTH;
	viewport->step.imag = ((viewport->center.imag + viewport->border.imag)
			- (viewport->center.imag - viewport->border.imag)) / DISPLAY_WIDTH;
	viewport->zoom = 1.0;
	viewport->zoom_elasticity = 1.0 / 3.0;
	viewport->initial_border = viewport->border;
	viewport->initial_center = viewport->center;
	viewport->initial_step = viewport->step;
}

static int	mandelbrot_algo(t_mlx *mlx, t_complex z, t_complex c)
{
	int			iterations;
	double		temp_imag;

	iterations = 0;
	z.real = 0.0;
	z.imag = 0.0;
	while (iterations < mlx->vars.max_iterations
		&& (z.real * z.real + z.imag * z.imag < 4.0))
	{
		temp_imag = 2 * z.real * z.imag + c.imag;
		z.real = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = temp_imag;
		iterations++;
	}
	return (iterations);
}

void	draw_mandelbrot(t_mlx *mlx, int x, int y)
{
	t_complex	c;
	t_complex	z;

	while (y < DISPLAY_WIDTH)
	{
		c.imag = (mlx->viewport.center.imag + mlx->viewport.border.imag)
			- (mlx->viewport.step.imag * y);
		x = 0;
		while (x < DISPLAY_LENGTH)
		{
			c.real = (mlx->viewport.center.real - mlx->viewport.border.real)
				+ (mlx->viewport.step.real * x);
			set_pixel(mlx, mandelbrot_algo(mlx, z, c), x, y);
			x++;
		}
		y++;
	}
}
