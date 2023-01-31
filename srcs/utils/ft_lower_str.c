/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:57:44 by nicolas           #+#    #+#             */
/*   Updated: 2023/01/19 10:13:58 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

char	*ft_lower_str(char *str)
{
	size_t		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
