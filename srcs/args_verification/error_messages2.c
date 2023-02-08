/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:23:10 by nplieger          #+#    #+#             */
/*   Updated: 2023/02/08 16:24:27 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_bool	error_invalid_argument_given(void)
{
	set_write_color(RED, 2);
	ft_putendl_fd("Error. Invalid argument given.", 2);
	error_indication();
	reset_write_color(2);
	return (FALSE);
}
