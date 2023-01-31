/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:55:21 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/30 19:02:26 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#define SCROLL_UP 4
#define SCROLL_DOWN 5

int	cursor_move(int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (mlx->vars.selected_fractal == julia)
		fill_display(mlx);
	return (0);
}

static void	mlx_zoom(int keycode, t_viewport *viewport, double x, double y)
{
	if (keycode == SCROLL_UP)
	{
		viewport->zoom *= 0.95;
		x = ((x * viewport->step.real) - viewport->border.real);
		y = ((y * viewport->step.imag) - viewport->border.imag);
		viewport->center.real += (x * viewport->zoom_elasticity);
		viewport->center.imag -= (y * viewport->zoom_elasticity);
	}
	else
	{
		viewport->zoom *= 1.05;
		x = ((x * viewport->step.real) - viewport->border.real);
		y = ((y * viewport->step.imag) - viewport->border.imag);
		viewport->center.real -= (x * viewport->zoom_elasticity);
		viewport->center.imag += (y * viewport->zoom_elasticity);
	}
	set_zoom(viewport);
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
