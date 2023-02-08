/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:44:08 by nicolas           #+#    #+#             */
/*   Updated: 2023/02/08 16:18:25 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static t_bool	handle_fractal_arg(char *arg, enum e_fractals *target)
{
	long long int	llint_arg;

	if (!ft_str_is_int(arg))
		arg = select_fractal_index(arg);
	if (arg)
	{
		llint_arg = ft_atolli(arg);
		if (!check_if_valid_int(llint_arg))
			return (FALSE);
		*target = llint_arg;
		arg = get_fractal_name_capitalized(*target);
	}
	if (!arg)
		return (error_unrecognized_fractal_name());
	return (TRUE);
}

static t_bool	handle_julia_args(int argc, char **argv,
	enum e_fractals *target, t_complex *julia_arg)
{
	julia_arg->real = 0.0;
	julia_arg->imag = 0.0;
	if (*target != julia && argc == 1)
		return (TRUE);
	else if (*target != julia)
		return (error_wrong_number_of_given_args(target));
	if (argc == 1)
		return (TRUE);
	if (argc != 3)
		return (error_wrong_number_of_given_args(target));
	if (!ft_str_is_double(argv[1]) || !ft_str_is_double(argv[2]))
		return (FALSE);
	julia_arg->real = ft_atold(argv[1]);
	julia_arg->imag = ft_atold(argv[2]);
	return (TRUE);
}

t_bool	verify_args(int argc, char **argv, enum e_fractals *target,
	t_complex *julia_arg)
{
	char	*arg;

	if (argc < 1)
		return (error_no_given_arg());
	*target = 0;
	arg = ft_lower_str(argv[0]);
	if (!handle_fractal_arg(arg, target))
		return (FALSE);
	if (!handle_julia_args(argc, argv, target, julia_arg))
		return (FALSE);
	return (TRUE);
}
