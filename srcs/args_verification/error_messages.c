/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/19 09:51:33 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_bool	error_indication(void)
{
	set_write_color_cyan(2);
	ft_putendl_fd("Expected usage : ./fract-ol [fractal_name or index].", 2);
	put_available_fractals(2);
	reset_write_color(2);
	return (FALSE);
}

t_bool	error_no_given_arg(int argc)
{
	if (argc != 0)
		return (FALSE);
	set_write_color_red(2);
	ft_putendl_fd("Error. No argument given.", 2);
	error_indication();
	reset_write_color(2);
	return (FALSE);
}

t_bool	error_excess_given_args(int argc)
{
	if (argc < 2)
		return (FALSE);
	set_write_color_red(2);
	ft_putendl_fd("Error. More than one argument given.", 2);
	error_indication();
	reset_write_color(2);
	return (FALSE);
}

t_bool	error_unrecognized_fractal_name(char *arg)
{
	if (arg)
		return (FALSE);
	set_write_color_red(2);
	ft_putendl_fd("Error. Unrecognized fractal.", 2);
	error_indication();
	reset_write_color(2);
	return (TRUE);
}

t_bool	check_if_valid_int(long long int llint)
{
	if (llint > MAX_INT || llint < MIN_INT)
	{
		set_write_color_red(2);
		ft_putendl_fd("Error. Given argument exceeds integer type limit.", 2);
		error_indication();
		reset_write_color(2);
		return (FALSE);
	}
	return (TRUE);
}
