/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:10:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/02/08 16:10:41 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_bool	error_indication(void)
{
	set_write_color(CYAN, 2);
	ft_putendl_fd("Expected usage : ./fract-ol [fractal_name or index].", 2);
	put_available_fractals(2);
	reset_write_color(2);
	return (FALSE);
}

t_bool	error_no_given_arg(void)
{
	set_write_color(RED, 2);
	ft_putendl_fd("Error. No argument given.", 2);
	error_indication();
	reset_write_color(2);
	return (FALSE);
}

t_bool	error_wrong_number_of_given_args(enum e_fractals *target)
{
	set_write_color(RED, 2);
	ft_putstr_fd("Error. ", 2);
	ft_putstr_fd(get_fractal_name_capitalized(*target), 2);
	ft_putendl_fd(" recognized. Wrong number of arguments given.", 2);
	error_indication();
	reset_write_color(2);
	return (FALSE);
}

t_bool	error_unrecognized_fractal_name(void)
{
	set_write_color(RED, 2);
	ft_putendl_fd("Error. Unrecognized fractal.", 2);
	error_indication();
	reset_write_color(2);
	return (FALSE);
}

t_bool	check_if_valid_int(long long int llint)
{
	if (llint > MAX_INT || llint < MIN_INT)
	{
		set_write_color(RED, 2);
		ft_putendl_fd("Error. Given argument exceeds integer type limit.", 2);
		error_indication();
		reset_write_color(2);
		return (FALSE);
	}
	return (TRUE);
}
