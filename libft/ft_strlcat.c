/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:09:58 by mbico             #+#    #+#             */
/*   Updated: 2023/11/02 12:41:16 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	lendst;

	i = 0;
	if (size == 0 && dst == NULL)
		return (0);
	lendst = ft_strlen(dst);
	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	while (dst[i] != 0)
		i ++;
	j = 0;
	while (i < size - 1 && src[j] != 0)
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	dst[i] = 0;
	return (ft_strlen(src) + lendst);
}
