/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:15:32 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/17 16:07:01 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* copie n octets depuis la zone mémoire src vers la zone mémoire dest*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	const double src[5] = {4.2,2.5,2.3,2.4,2.8};
	double dest[5];

	ft_memcpy(dest,src,sizeof(src));
	for (int i = 0; i < 5; i++)
	{
		printf("%f",dest[i]);
	}

	//printf("%s", ft_memcpy(dest, src, 4));
} */