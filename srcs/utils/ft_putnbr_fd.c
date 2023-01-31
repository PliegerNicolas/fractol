/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:56:46 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/18 16:10:13 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		chars;

	chars = 0;
	if (n == MIN_INT)
	{
		chars += ft_putnbr_fd((n / 10), fd);
		chars += ft_putnbr_fd(-(n % 10), fd);
	}
	else
	{
		if (n < 0)
		{
			chars += ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			chars += ft_putnbr_fd(n / 10, fd);
			chars += ft_putnbr_fd(n % 10, fd);
		}
		else
			chars += ft_putchar_fd(n + '0', fd);
	}
	return (chars);
}
