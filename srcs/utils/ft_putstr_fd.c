/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:57:26 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/18 14:58:08 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_putstr_fd(char *s, int fd)
{
	int		chars;

	chars = 0;
	if (!s)
		return (chars);
	while (*s)
		chars += write(fd, s++, 1);
	return (chars);
}
