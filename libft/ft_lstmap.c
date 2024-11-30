/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:47:32 by mbico             #+#    #+#             */
/*   Updated: 2023/11/08 22:34:42 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nl;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	nl = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstdelone(nl, del);
			return (NULL);
		}
		ft_lstadd_back(&nl, node);
		lst = lst->next;
	}
	return (nl);
}
