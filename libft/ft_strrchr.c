/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:01:21 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/17 17:31:14 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* renvoie un pointeur sur la dernière occurrence
	du caractère c dans la chaîne s  */
char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if ((unsigned char)s[len] == (unsigned char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	const char *s = "on va faire des tests";
	int c = 's';
	printf("%s", ft_strrchr(s, c));
}*/