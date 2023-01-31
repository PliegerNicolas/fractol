/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tricorn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:27:21 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 15:51:19 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	init_tricorn_algo(t_viewport *viewport)
{
	viewport->screen_ratio = (double)DISPLAY_LENGTH / (double)DISPLAY_WIDTH;
	viewport->border.real = 2.75;
	viewport->border.imag = 2.0;
	viewport->center.real = 0.0;
	viewport->center.imag = -0.5;
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

static int	tricorn_algo(t_mlx *mlx, t_complex z, t_complex c)
{
	int			iterations;
	double		temp_imag;

	iterations = 0;
	while (iterations < mlx->vars.max_iterations
		&& (z.real * z.real + z.imag * z.imag < 4.0))
	{
		temp_imag = z.imag * z.imag - z.real * z.real + c.imag;
		z.real = -2.0 * z.real * z.imag + c.real;
		z.imag = temp_imag;
		iterations++;
	}
	return (iterations);
}

void	draw_tricorn(t_mlx *mlx, int x, int y)
{
	t_complex	c;
	t_complex	z;

	z.real = 0;
	z.imag = 0;
	while (y < DISPLAY_WIDTH)
	{
		c.imag = (mlx->viewport.center.imag + mlx->viewport.border.imag)
			- (mlx->viewport.step.imag * y);
		x = 0;
		while (x < DISPLAY_LENGTH)
		{
			c.real = (mlx->viewport.center.real - mlx->viewport.border.real)
				+ (mlx->viewport.step.real * x);
			set_pixel(mlx, tricorn_algo(mlx, z, c), x, y);
			x++;
		}
		y++;
	}
}
