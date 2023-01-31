/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_iterations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:24:22 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/30 18:55:41 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	hook_iterations(int keycode, t_mlx *mlx)
{
	if (keycode == XK_q && mlx->vars.max_iterations < 200)
		mlx->vars.max_iterations++;
	else if (keycode == XK_w && mlx->vars.max_iterations > 2)
		mlx->vars.max_iterations--;
	else
		return (0);
	return (1);
}
