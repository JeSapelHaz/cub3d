/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:24:11 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/16 16:05:23 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* va chercher le caractere dans le pointeur donne en jouant avec 
	les adresses */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	const char *s = "on va faire des tests";
	int c = 'a';
	
	printf("%s", ft_memchr(s, c, 20));
}*/