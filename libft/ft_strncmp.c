/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:06:49 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/12 15:43:28 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char			*s1;
	char			*s2;
	unsigned int	n;
	char			*s3;
	char			*s4;

	s1 = "test\200";
	s2 = "test\0";
	n = 6;
	printf("%d \n", ft_strncmp(s1, s2, 6));
	s3 = "test\200";
	s4 = "test\0";
	printf("%d ", strncmp(s3, s4, 6));
}
 */