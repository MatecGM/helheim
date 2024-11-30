/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:27:09 by mbico             #+#    #+#             */
/*   Updated: 2023/11/10 17:47:30 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst && *lst && del)
	{
		if (lst[0]->next)
			ft_lstclear(&lst[0]->next, del);
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
	else if (lst)
		*lst = NULL;
}
