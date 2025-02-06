/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:29:15 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/23 17:54:42 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* cree une nouvelle liste et renvoie avec chaque element de lst
	applique par la fonction f */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*a;
	void	*node;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node = f(lst->content);
		a = ft_lstnew(node);
		if (!a)
		{
			del(node);
			ft_lstclear(&new, (*del));
			return (new);
		}
		ft_lstadd_back(&new, a);
		lst = lst->next;
	}
	return (new);
}
