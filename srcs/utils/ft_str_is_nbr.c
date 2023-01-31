/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:11:08 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/18 17:13:45 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_bool	ft_str_is_nbr(char *arg)
{
	if (!arg)
		return (FALSE);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}
