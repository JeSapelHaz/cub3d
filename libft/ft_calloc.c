/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:47:13 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/24 14:30:48 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* va donnner la bonne taille et va tout initialiser a 0 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*m;
	size_t	total;

	total = nmemb * size;
	if (size != 0 && (total / size) != nmemb)
		return (NULL);
	m = malloc(total);
	if (!m)
		return (NULL);
	ft_bzero(m, total);
	return (m);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	long long	nmemb;
// 	char *ptr;
// 	long long	size;

// 	nmemb = 554564356;
// 	size = 3515613515613513;
// 	ptr = calloc(nmemb, size);
// }
