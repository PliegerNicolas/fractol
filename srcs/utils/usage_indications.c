/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_indications.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:25:38 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 18:07:16 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	usage_indications(void)
{
	set_write_color(CYAN, 1);
	put_available_fractals(1);
	ft_putchar_fd('\n', 1);
	set_write_color(GREEN, 1);
	ft_putendl_fd("Controls :", 1);
	ft_putendl_fd("== == == == == == == == == ==", 1);
	set_write_color(CYAN, 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("॰ Select fractal by index : '1', '2', '3', '4', ...", 1);
	ft_putendl_fd("॰ Modify precision : 'q' & 'w'.", 1);
	ft_putendl_fd("॰ Zoom in or out : '+', '-', 'scroll'.", 1);
	ft_putendl_fd("॰ Move around : arrow keys.", 1);
	ft_putendl_fd("॰ Shift colors : 'a' & 's' shift.", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("॰ With Julia (2) : cursor position is a factor.", 1);
	ft_putchar_fd('\n', 1);
	set_write_color(GREEN, 1);
	ft_putendl_fd("== == == == == == == == == ==", 1);
	reset_write_color(1);
}
