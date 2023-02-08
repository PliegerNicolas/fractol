/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:45:39 by nplieger          #+#    #+#             */
/*   Updated: 2023/02/08 13:09:41 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#define X 17
#define BUTTON_PRESS_AND_MOUSE 4
#define KEY_PRESS 2
#define MOUSE_MOTION_NOTIFY 6

static int	mlx_exit(t_mlx *mlx)
{
	if (!mlx->mlx_ptr)
		exit (0);
	if (mlx->vars.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->vars.img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	exit (0);
}

static int	set_key_hooks(int keycode, t_mlx *mlx)
{
	if (!mlx)
		return (1);
	else if (keycode == XK_Escape)
		mlx_exit(mlx);
	else if (hook_zoom(keycode, mlx))
		fill_display(mlx);
	else if (hook_iterations(keycode, mlx))
		fill_display(mlx);
	else if (hook_arrows(keycode, mlx))
		fill_display(mlx);
	else if (hook_colorshift(keycode, &mlx->vars.color))
		fill_display(mlx);
	else if (hook_numbers(keycode, mlx))
		fill_display(mlx);
	return (0);
}

void	set_hooks(t_mlx	*mlx)
{
	if (!mlx)
		return ;
	mlx_hook(mlx->win_ptr, X, 1L << 17, mlx_exit, mlx);
	mlx_hook(mlx->win_ptr, KEY_PRESS, 1L << 0, set_key_hooks, mlx);
	mlx_hook(mlx->win_ptr, BUTTON_PRESS_AND_MOUSE, 1L << 2, hook_mouse, mlx);
	mlx_hook(mlx->win_ptr, MOUSE_MOTION_NOTIFY, 1L << 8, cursor_move, mlx);
}
