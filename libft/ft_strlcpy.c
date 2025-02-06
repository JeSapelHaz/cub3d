/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:49:10 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/11 15:39:48 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* copie la src dans dest en controlant sa taille et eviter les overflow */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (!dest || !src)
		return (0);
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	return (len);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[14] = "salut les amis";
	char dest[14] = "";
	size_t size = 5;
	printf("%zu", ft_strlcpy(dest, str, size));
	printf("%s", dest);
} */
