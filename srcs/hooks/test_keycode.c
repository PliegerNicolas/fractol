/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_keycode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:59:47 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/21 21:14:50 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	key_hook(int keycode, t_mlx *mlx)
{
	ft_putnbr_fd(keycode, 1);
	ft_putchar_fd('\n', 1);
	(void)mlx;
	return (0);
}

void	test_keycode(t_mlx *mlx)
{
	mlx_key_hook(mlx->win_ptr, key_hook, mlx);
}
