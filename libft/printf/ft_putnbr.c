/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:32:16 by mbico             #+#    #+#             */
/*   Updated: 2024/01/31 18:25:35 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_negative_number(int n, int *len)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len[0]++;
	}
	return (n);
}

static int	ft_minint(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_putnbr(int n)
{
	int	d;
	int	c;
	int	len;

	d = 1;
	c = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_minint());
	n = ft_negative_number(n, &len);
	c = n;
	while (c > 9)
	{
		c = c / 10;
		d = d * 10;
	}
	c = n;
	while (d > 0)
	{
		ft_putchar_printf('0' + c / d);
		c = c % d;
		d = d / 10;
		len ++;
	}
	return (len);
}
