/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:55:41 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/18 14:56:30 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_putendl_fd(char *s, int fd)
{
	int		chars;

	chars = 0;
	if (!s)
		return (chars);
	chars += ft_putstr_fd(s, fd);
	chars += ft_putchar_fd('\n', fd);
	return (chars);
}
