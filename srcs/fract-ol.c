/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:23 by nicolas           #+#    #+#             */
/*   Updated: 2023/02/08 15:06:10 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	initialize_mlx(t_mlx *mlx, t_complex julia_arg)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, DISPLAY_LENGTH, DISPLAY_WIDTH,
			TITLE);
	mlx->vars.img = NULL;
	mlx->vars.cursor_pos.real = julia_arg.real;
	mlx->vars.cursor_pos.imag = julia_arg.imag;
}

int	main(int argc, char **argv)
{
	t_mlx			mlx;
	enum e_fractals	target;
	t_complex		julia_arg;

	if (!verify_args(argc - 1, argv + 1, &target, &julia_arg))
		return (1);
	usage_indications();
	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	select_fractal(&mlx, target);
	initialize_mlx(&mlx, julia_arg);
	set_hooks(&mlx);
	fill_display(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
