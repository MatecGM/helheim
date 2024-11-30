/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:02:00 by mbico             #+#    #+#             */
/*   Updated: 2023/11/09 17:21:57 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = NULL;
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			occ = (char *)s;
		s ++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (occ);
}
