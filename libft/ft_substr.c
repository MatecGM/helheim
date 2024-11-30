/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:38:39 by mateo             #+#    #+#             */
/*   Updated: 2023/11/09 18:19:43 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	len_s = 0;
	while (s[start + len_s] && len_s < len)
		len_s ++;
	str = malloc((len_s + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		str[i] = s[start + i];
		i ++;
	}
	str[i] = 0;
	return (str);
}
