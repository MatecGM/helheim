/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:15:19 by mbico             #+#    #+#             */
/*   Updated: 2023/11/08 20:23:51 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	len = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		len ++;
	}
	return (len);
}
