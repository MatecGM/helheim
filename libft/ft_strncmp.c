/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:14 by mbico             #+#    #+#             */
/*   Updated: 2023/11/10 17:11:15 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < n - 1 && (unsigned char)(s1[i]) && (unsigned char)(s2[i])
		&& (unsigned char)(s1[i]) == (unsigned char)(s2[i]))
	{
		i ++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
