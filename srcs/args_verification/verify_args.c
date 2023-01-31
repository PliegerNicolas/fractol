/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:44:08 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/23 02:57:48 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

/*
static char	*select_fractal(int arg)
{
	char				*fractal_name;
	enum e_fractals		fractal_enum;

	fractal_enum = arg;
	fractal_name = get_fractal_name(fractal_enum);
	if (error_unrecognized_fractal_name(fractal_name))
		return (NULL);
	return (fractal_name);
}
*/

t_bool	verify_args(int argc, char **argv, enum e_fractals *target)
{
	char			*arg;
	long long int	llint_arg;

	if (!argc)
		return (error_no_given_arg(argc));
	if (argc > 1)
		return (error_excess_given_args(argc));
	*target = 0;
	arg = ft_lower_str(argv[0]);
	if (!ft_str_is_nbr(argv[0]))
		arg = select_fractal_index(arg);
	if (error_unrecognized_fractal_name(arg))
		return (FALSE);
	llint_arg = ft_atolli(arg);
	if (!check_if_valid_int(llint_arg))
		return (FALSE);
	*target = (int)llint_arg;
	arg = get_fractal_name_capitalized(*target);
	if (!arg)
		return (!error_unrecognized_fractal_name(arg));
	return (TRUE);
}
