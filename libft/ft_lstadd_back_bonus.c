/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:26:19 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/16 16:04:46 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* creer une list temporaire, qui va pointer vers le premier element de la liste
	vq pqrcourir lq liste, et lorsque qu on est a la fin de la list il va
	rajouter le new*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next)
		t = t->next;
	t->next = new;
}

/* #include <stdio.h>
int	main(void)
{
	t_list *lst = ft_lstnew("Hello");
	ft_lstadd_front(&lst, ft_lstnew("World"));
	ft_lstadd_front(&lst, ft_lstnew("Salut"));
	ft_lstadd_back(&lst, ft_lstnew("dernier"));
	printf("%s", ft_lstlast(lst)->content);
} */
