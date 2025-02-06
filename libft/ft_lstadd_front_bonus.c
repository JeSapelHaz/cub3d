/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:24:24 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/23 17:53:08 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Le pointeur next de la nouvelle cellule new est configuré pour pointer
	vers l'ancienne première cellule de la liste.
	Cela garantit que la nouvelle cellule est connectée à la liste */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	new = ft_lstnew("Hello");
	ft_lstadd_front(&lst, new);
	lst = ft_lstnew("Hello");
	new = ft_lstnew("World");
	ft_lstadd_front(&lst, new);
	printf("%s",lst->content);
}
 */