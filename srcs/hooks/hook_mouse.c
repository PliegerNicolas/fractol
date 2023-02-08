/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:55:21 by nicolas           #+#    #+#             */
/*   Updated: 2023/02/08 13:09:35 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#define SCROLL_UP 4
#define SCROLL_DOWN 5

int	cursor_move(int x, int y, t_mlx *mlx)
{
	if (mlx->vars.selected_fractal == julia)
	{
		mlx->vars.cursor_pos.real = (mlx->viewport.center.real
				- mlx->viewport.border.real)
			+ (mlx->viewport.step.real * (double)x);
		mlx->vars.cursor_pos.imag = (mlx->viewport.center.imag
				+ mlx->viewport.border.imag)
			- (mlx->viewport.step.imag * (double)y);
		fill_display(mlx);
	}
	return (0);
}

void	mlx_zoom(int keycode, t_viewport *viewport, double x, double y)
{
	t_complex	old;

	if (keycode == SCROLL_UP)
	{
		old.real = ((x * viewport->step.real) - viewport->border.real);
		old.imag = ((y * viewport->step.imag) - viewport->border.imag);
		viewport->zoom *= 0.95;
		set_zoom(viewport);
		x = ((x * viewport->step.real) - viewport->border.real);
		y = ((y * viewport->step.imag) - viewport->border.imag);
		viewport->center.real += old.real - x;
		viewport->center.imag -= old.imag - y;
	}
	else if (keycode == SCROLL_DOWN)
	{
		old.real = ((x * viewport->step.real) - viewport->border.real);
		old.imag = ((y * viewport->step.imag) - viewport->border.imag);
		viewport->zoom *= 1.05;
		set_zoom(viewport);
		x = ((x * viewport->step.real) - viewport->border.real);
		y = ((y * viewport->step.imag) - viewport->border.imag);
		viewport->center.real += old.real - x;
		viewport->center.imag -= old.imag - y;
	}
}

int	hook_mouse(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
		mlx_zoom(keycode, &mlx->viewport, x, y);
	else
		return (0);
	fill_display(mlx);
	return (1);
}
