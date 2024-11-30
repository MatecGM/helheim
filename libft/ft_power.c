/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:04:28 by mbico             #+#    #+#             */
/*   Updated: 2024/08/25 09:02:28 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_power(double nb, int power)
{
	double	res;
	
	res = nb;
	while (power > 0)
	{
		res = res * res;
		power --;
	}
	return (res);
}