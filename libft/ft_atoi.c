/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:36:32 by mbico             #+#    #+#             */
/*   Updated: 2023/11/10 19:07:58 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while ((*nptr && *nptr == ' ') || (*nptr && *nptr >= 9 && *nptr <= 13))
		nptr ++;
	if (*nptr && (*nptr == '+' || *nptr == '-'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr ++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr ++;
	}
	nbr *= sign;
	return (nbr);
}
