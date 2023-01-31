/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_arrows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:39:43 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/30 18:55:07 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	hook_arrows(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Left)
		mlx->viewport.center.real -= 10 * mlx->viewport.step.real;
	else if (keycode == XK_Right)
		mlx->viewport.center.real += 10 * mlx->viewport.step.real;
	else if (keycode == XK_Up)
		mlx->viewport.center.imag += 10 * mlx->viewport.step.imag;
	else if (keycode == XK_Down)
		mlx->viewport.center.imag -= 10 * mlx->viewport.step.imag;
	else
		return (0);
	return (1);
}
