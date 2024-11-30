/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:26:39 by mbico             #+#    #+#             */
/*   Updated: 2024/01/31 18:25:01 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_choiceft(char chr, va_list args)
{
	if (chr == 'c')
		return (ft_putchar_printf(va_arg(args, int)));
	else if (chr == 's')
		return (ft_putstr_printf(va_arg(args, char *)));
	else if (chr == 'p')
		return (ft_nil(va_arg(args, unsigned long)));
	else if (chr == 'd' || chr == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (chr == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (chr == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (chr == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (chr == '%')
		return (ft_putchar_printf('%'));
	return (0);
}

int	ft_basicinput(va_list args, const char *str, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (ft_strrchr_printf("cspdiuxX%", str[i + 1]))
			{
				len += ft_choiceft(str[i + 1], args);
				i += 2;
			}
			else
				i += 2;
		}
		else if (str[i] == '%' && !str[i + 1])
			return (-1);
		else
		{
			write(1, &str[i++], 1);
			len ++;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	if (!str)
		return (-1);
	len = 0;
	va_start(args, str);
	len = ft_basicinput(args, str, len);
	va_end(args);
	return (len);
}
