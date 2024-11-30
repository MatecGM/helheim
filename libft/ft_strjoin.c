/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:20:49 by mateo             #+#    #+#             */
/*   Updated: 2023/11/09 18:57:22 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*s3;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc((total_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		s3[i] = *s1;
		i ++;
		s1 ++;
	}
	while (*s2)
	{
		s3[i] = *s2;
		i ++;
		s2 ++;
	}
	s3[i] = 0;
	return (s3);
}
