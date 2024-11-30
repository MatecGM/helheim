/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:39:31 by mbico             #+#    #+#             */
/*   Updated: 2024/01/31 18:21:40 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include "../libft.h"

char	*ft_strrchr_printf(const char *s, int c);
int		ft_putstr_printf(char *s);
int		ft_putchar_printf(char c);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_putnbr(int n);
int		ft_nil(unsigned long n);
int		ft_printf(const char *str, ...);

#endif
