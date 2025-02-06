/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:00:54 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/23 17:55:13 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compte le nombre de caracteres */
static int	ft_count(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/* malloc la bonne taille grace a la fonction count
	et va retourner chaque dizaine en caractere */
char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		neg;
	long	nb;

	neg = 0;
	count = ft_count(n);
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
		neg = 1;
	}
	while (neg <= --count)
	{
		str[count] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%s", ft_itoa(-29861616));
// }