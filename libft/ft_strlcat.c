/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:41:06 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/16 15:43:25 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(dest);
	k = j;
	if (size <= j || size == 0)
		return (ft_strlen(src) + size);
	while (src[i] && i < size - k - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (ft_strlen(src) + k);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dest[40] = "salut";
	char *src = "les amis";

	printf("%lu ",strlcat(dest, src, 4));
	printf("%s ",dest);
	char dest2[40] = "salut";
	char *src2 = "les amis";

	printf("%u ",ft_strlcat(dest2, src2, 4));
	printf("%s ",dest2);
}
*/
