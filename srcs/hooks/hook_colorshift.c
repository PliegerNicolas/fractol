/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_colorshift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:07:44 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 15:32:46 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	hook_colorshift(int keycode, t_trgb *color)
{
	if (keycode == XK_a)
		color->shift *= 1.02;
	else if (keycode == XK_s)
		color->shift *= 0.98;
	else
		return (0);
	return (1);
}
