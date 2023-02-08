/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:11:08 by nicolas           #+#    #+#             */
/*   Updated: 2023/02/08 15:55:21 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_bool	ft_str_is_int(char *arg)
{
	if (!arg)
		return (FALSE);
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

t_bool	ft_str_is_double(char *arg)
{
	if (!arg)
		return (FALSE);
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg && ft_isdigit(*arg))
		arg++;
	if (!*arg)
		return (TRUE);
	if (*arg == '.' || *arg == ',')
		arg++;
	else
		return (FALSE);
	while (*arg && ft_isdigit(*arg))
		arg++;
	if (*arg != '\0')
		return (FALSE);
	return (TRUE);
}
