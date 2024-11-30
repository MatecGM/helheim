/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:42:46 by mbico             #+#    #+#             */
/*   Updated: 2023/11/02 19:35:29 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		k = 0;
		while (big[i + k] == little[k] && big[i + k] && i + k < len)
			k ++;
		if (little[k] == 0)
			return ((char *)big + i);
		i ++;
	}
	return (NULL);
}
