/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:06:27 by nicolas           #+#    #+#             */
/*   Updated: 2023/02/08 16:20:10 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

char	*get_fractal_name_capitalized(enum e_fractals fractal)
{
	if (fractal == 1)
		return ("Mandelbrot");
	else if (fractal == 2)
		return ("Julia");
	else if (fractal == 3)
		return ("Burning_Ship");
	else if (fractal == 4)
		return ("Tricorn");
	return (NULL);
}

char	*select_fractal_index(char *arg)
{
	if (!ft_strcmp(arg, "mandelbrot"))
		return ("1");
	else if (!ft_strcmp(arg, "julia"))
		return ("2");
	else if (!ft_strcmp(arg, "burning_ship"))
		return ("3");
	else if (!ft_strcmp(arg, "tricorn"))
		return ("4");
	return (NULL);
}

void	put_available_fractals(int fd)
{
	enum e_fractals		fract_enum;
	char				*fract_name;
	int					i;

	ft_putendl_fd("Available fractals are as follows :", fd);
	fract_name = "";
	i = 1;
	while (fract_name)
	{
		fract_enum = i;
		fract_name = get_fractal_name_capitalized(fract_enum);
		if (!fract_name)
			break ;
		ft_putstr_fd("॰ ", fd);
		ft_putnbr_fd(i++, fd);
		ft_putstr_fd(" : ", fd);
		ft_putstr_fd(fract_name, fd);
		if (fract_enum == julia)
			ft_putstr_fd(" (optional arguments -> [real double] [imag double])", fd);
		ft_putchar_fd('\n', fd);
	}
}
