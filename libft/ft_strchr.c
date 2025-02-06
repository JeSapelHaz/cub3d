/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:47:29 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/12 14:56:11 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* renvoie un pointeur sur la première occurrence
	du caractère c dans la chaîne s */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&(s[i]));
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	const char *s = "on va faire des tests";
	int c = 'd';
	printf("%s", ft_strchr(s, c));
}*/