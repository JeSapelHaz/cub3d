/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:32:25 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/16 15:02:13 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* remplit s avec c jusqu a n */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char s[10] = "salut";
	int c;
	size_t n;


	c = 400;
	n = 2;

	ft_memset(s, c, n);
	printf("%s", s);
}*/