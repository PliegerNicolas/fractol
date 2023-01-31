/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:08:30 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 02:11:53 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	select_color(t_mlx *mlx, int iterations)
{
	t_trgb	color;

	color = mlx->vars.color;
	color.red_freq *= color.shift;
	color.green_freq *= color.shift;
	color.blue_freq *= color.shift;
	color.red = sin(fmod(color.red_freq * iterations + color.red_phase,
				3 * M_PI)) * color.width + color.center;
	color.green = sin(fmod(color.green_freq * iterations + color.green_phase,
				2 * M_PI)) * color.width + color.center;
	color.blue = sin(fmod(color.blue_freq * iterations + color.blue_phase,
				1 * M_PI)) * color.width + color.center;
	return (create_trgb(225, color.red, color.green, color.blue));
}

void	set_pixel(t_mlx *mlx, int iterations, int pixel_x, int pixel_y)
{
	if (iterations == mlx->vars.max_iterations)
		my_mlx_pixel_put(&mlx->vars, pixel_x, pixel_y, create_trgb(0, 0, 0, 0));
	else
		my_mlx_pixel_put(&mlx->vars, pixel_x, pixel_y,
			select_color(mlx, iterations));
}
