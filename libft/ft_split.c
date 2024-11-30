/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:48:16 by mateo             #+#    #+#             */
/*   Updated: 2023/11/10 19:05:07 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] == c && s[i])
		i ++;
	while (s[i])
	{
		counter ++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (counter);
}

static size_t	ft_wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len ++;
	return (len);
}

static void	*ft_freeall(char **splitted_char, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(splitted_char[i]);
		i ++;
	}
	free(splitted_char);
	return (NULL);
}

static char	**ft_createword(char const *s, char **splitted_char, int c, int i)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		splitted_char[j] = malloc((ft_wordlen(s, c, i) + 1) * sizeof(char));
		if (splitted_char[j] == NULL)
			return (ft_freeall(splitted_char, j));
		k = 0;
		while (s[i] && s[i] != c)
		{
			splitted_char[j][k] = s[i];
			k ++;
			i ++;
		}
		splitted_char[j][k] = '\0';
		while (s[i] == c && s[i])
			i++;
		j ++;
	}
	splitted_char[j] = NULL;
	return (splitted_char);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_char;
	size_t	i;

	if (s == NULL)
		return (NULL);
	splitted_char = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (splitted_char == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (ft_createword(s, splitted_char, c, i));
}
