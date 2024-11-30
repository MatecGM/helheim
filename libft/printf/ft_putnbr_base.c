/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:32:16 by mbico             #+#    #+#             */
/*   Updated: 2024/01/31 18:25:22 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nil(unsigned long n)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + ft_putnbr_base(n, "0123456789abcdef"));
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	d;
	unsigned long	c;
	int				len;
	unsigned long	lenbase;

	d = 1;
	len = 0;
	c = n;
	lenbase = ft_strlen(base);
	while (c > lenbase - 1)
	{
		c = c / lenbase;
		d = d * lenbase;
	}
	c = n;
	while (d > 0)
	{
		ft_putchar_printf(base[c / d]);
		c = c % d;
		d = d / lenbase;
		len ++;
	}
	return (len);
}
