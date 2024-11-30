/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:29:13 by mbico             #+#    #+#             */
/*   Updated: 2023/11/10 19:05:00 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_output(char n, int fd)
{
	write(fd, &n, 1);
}

static int	ft_negative_number(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	d;
	int	c;

	d = 1;
	c = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		n = ft_negative_number(n, fd);
		c = n;
		while (c > 9)
		{
			c = c / 10;
			d = d * 10;
		}
		c = n;
		while (d > 0)
		{
			ft_output('0' + c / d, fd);
			c = c % d;
			d = d / 10;
		}
	}
}
