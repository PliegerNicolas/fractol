/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_write_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:35:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/18 15:43:51 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	set_write_color_red(int fd)
{
	ft_putstr_fd(RED, fd);
}

void	set_write_color_green(int fd)
{
	ft_putstr_fd(GREEN, fd);
}

void	set_write_color_cyan(int fd)
{
	ft_putstr_fd(CYAN, fd);
}

void	reset_write_color(int fd)
{
	ft_putstr_fd("\033[0m", fd);
}
