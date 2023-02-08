/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:16:36 by nicolas           #+#    #+#             */
/*   Updated: 2023/02/08 11:33:15 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	init_julia_algo(t_viewport *viewport)
{
	viewport->screen_ratio = (double)DISPLAY_LENGTH / (double)DISPLAY_WIDTH;
	viewport->border.real = 2.0;
	viewport->border.imag = 1.15;
	viewport->center.real = 0.0;
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

static int	julia_algo(t_mlx *mlx, t_complex z, t_complex c)
{
	int			iterations;
	double		temp_imag;

	iterations = 0;
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

void	draw_julia(t_mlx *mlx, int x, int y)
{
	t_complex	c;
	t_complex	z;

	//mlx_mouse_get_pos(mlx->mlx_ptr, mlx->win_ptr, &cursor.x, &cursor.y);
	//c.real = (mlx->viewport.center.real - mlx->viewport.border.real)
	//	+ (mlx->viewport.step.real * (double)mlx->vars.cursor_pos.x);
	//c.imag = (mlx->viewport.center.imag + mlx->viewport.border.imag)
	//	- (mlx->viewport.step.imag * (double)mlx->vars.cursor_pos.y);
	c.real = mlx->vars.cursor_pos.real;
	c.imag = mlx->vars.cursor_pos.imag;
	while (y < DISPLAY_WIDTH)
	{
		z.imag = (mlx->viewport.center.imag + mlx->viewport.border.imag)
			- (mlx->viewport.step.imag * y);
		x = 0;
		while (x < DISPLAY_LENGTH)
		{
			z.real = (mlx->viewport.center.real - mlx->viewport.border.real)
				+ (mlx->viewport.step.real * x);
			set_pixel(mlx, julia_algo(mlx, z, c), x, y);
			x++;
		}
		y++;
	}
}
