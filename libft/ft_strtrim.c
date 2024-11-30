/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:56:18 by mateo             #+#    #+#             */
/*   Updated: 2023/11/06 17:47:37 by mbico            ###  ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lastchar(char const *s1, char const *set)
{
	int		max;

	max = ft_strlen(s1);
	while (NULL != ft_strchr(set, s1[max]))
		max --;
	return (max);
}

static int	ft_firstchar(char const *s1, char const *set)
{
	int		min;

	min = 0;
	while (NULL != ft_strchr(set, s1[min]))
	{
		min ++;
	}
	return (min);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		min;
	int		max;
	int		i;

	if (s1 == NULL)
		return (NULL);
	max = ft_lastchar(s1, set);
	min = ft_firstchar(s1, set);
	if (max < min)
		res = malloc((1) * sizeof(char));
	else
		res = malloc((max - min + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (min <= max)
	{
		res[i] = s1[min];
		min ++;
		i ++;
	}
	res[i] = 0;
	return (res);
}
