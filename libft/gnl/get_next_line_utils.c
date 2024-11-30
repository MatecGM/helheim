/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:37:24 by mbico             #+#    #+#             */
/*   Updated: 2024/01/10 17:25:25 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strbanlen(const char *s, char ban)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
	{
		if (s[len] == ban)
			return (len + 1);
		len ++;
	}
	return (len);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		total_len;
	char	*s3;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_len = ft_strbanlen(s1, 0) + ft_strbanlen(s2, 0);
	s3 = malloc((total_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		s3[i++] = s1[j++];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	free(s1);
	free(s2);
	s3[i] = 0;
	return (s3);
}

char	*ft_strdupn(const char *s)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strbanlen(s, '\n');
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i ++;
	}
	str[i] = 0;
	return (str);
}

void	*ft_freeall_gnl(char *buffer, char *line)
{
	if (line)
		free(line);
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (NULL);
}
