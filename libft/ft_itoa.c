/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:05:39 by mbico             #+#    #+#             */
/*   Updated: 2023/11/16 14:24:34 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(int n)
{
	int		len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static char	*ft_setnbr(char *ret, int n, int i, int len)
{
	int	c;

	c = 1;
	len --;
	while (len > 0)
	{
		c *= 10;
		len --;
	}
	while (c > 0)
	{
		ret[i] = (n / c) + '0';
		n %= c;
		c /= 10;
		i ++;
	}
	ret[i] = 0;
	return (ret);
}

static char	*ft_minint(char *ret, int n, int i, int len)
{
	if (n == -2147483648)
	{
		ret = ft_setnbr(ret, 2147483647, i, len);
		ret[len] = 8 + '0';
		return (ret);
	}
	return (ft_setnbr(ret, n, i, len));
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		sign;
	int		i;

	len = ft_lennbr(n);
	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		len ++;
	}
	ret = malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	if (sign == -1)
	{
		n = -n;
		ret[i] = '-';
		i ++;
		len --;
	}
	return (ft_minint(ret, n, i, len));
}
