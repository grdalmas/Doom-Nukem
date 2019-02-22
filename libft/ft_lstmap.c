/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:44:18 by cmartine          #+#    #+#             */
/*   Updated: 2017/11/27 13:10:22 by cmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst2;
	t_list *start;

	if (lst != NULL)
	{
		if (!(start = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		start = f(lst);
		lst2 = start;
		while (lst->next != NULL)
		{
			lst = lst->next;
			lst2->next = f(lst);
			lst2 = lst2->next;
		}
		lst2 = NULL;
		return (start);
	}
	return (NULL);
}
