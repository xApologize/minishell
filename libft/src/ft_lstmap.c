/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:23:55 by jrossign          #+#    #+#             */
/*   Updated: 2022/03/03 11:17:54 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;

	if (!lst)
	{
		ft_lstdelone(lst, *del);
		return (NULL);
	}
	newlist = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&newlist, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (newlist);
}
