/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:06:30 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/30 16:24:28 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static void	create_new_img(t_mlx *mlx)
{
	mlx->vars.img = mlx_new_image(mlx->mlx_ptr, DISPLAY_LENGTH, DISPLAY_WIDTH);
	mlx->vars.addr = mlx_get_data_addr(mlx->vars.img, &mlx->vars.bits_per_pixel,
			&mlx->vars.line_length, &mlx->vars.endian);
}

void	fill_display(t_mlx *mlx)
{
	create_new_img(mlx);
	if (mlx->vars.selected_fractal == mandelbrot)
		draw_mandelbrot(mlx, 0, 0);
	else if (mlx->vars.selected_fractal == julia)
		draw_julia(mlx, 0, 0);
	else if (mlx->vars.selected_fractal == burning_ship)
		draw_burning_ship(mlx, 0, 0);
	else if (mlx->vars.selected_fractal == tricorn)
		draw_tricorn(mlx, 0, 0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->vars.img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->vars.img);
	mlx->vars.img = NULL;
}
