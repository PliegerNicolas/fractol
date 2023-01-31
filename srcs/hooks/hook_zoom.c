/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:56:30 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/30 18:59:45 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	set_zoom(t_viewport *viewport)
{
	viewport->border.real = viewport->initial_border.real * viewport->zoom;
	viewport->border.imag = viewport->initial_border.imag * viewport->zoom;
	viewport->step.real = viewport->initial_step.real * viewport->zoom;
	viewport->step.imag = viewport->initial_step.imag * viewport->zoom;
}

int	hook_zoom(int keycode, t_mlx *mlx)
{
	if (keycode == XK_plus || keycode == XK_KP_Add)
	{
		mlx->viewport.zoom *= 0.95;
		set_zoom(&mlx->viewport);
	}
	else if (keycode == XK_minus || keycode == XK_KP_Subtract)
	{
		mlx->viewport.zoom *= 1.05;
		set_zoom(&mlx->viewport);
	}
	else
		return (0);
	return (1);
}
