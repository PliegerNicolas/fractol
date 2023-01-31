/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_write_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:35:59 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/31 18:05:50 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	set_write_color(char *s, int fd)
{
	ft_putstr_fd(s, fd);
}

void	reset_write_color(int fd)
{
	ft_putstr_fd("\033[0m", fd);
}
