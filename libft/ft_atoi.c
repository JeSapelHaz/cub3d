/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:39:14 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/23 18:12:10 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	char		sign;
	long int	result;
	long int	tmp;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		tmp = result;
		result = result * 10 + (*str - 48);
		if (result < tmp && sign == 1)
			return (-1);
		if (result < tmp && sign == -1)
			return (0);
		str++;
	}
	return (result * sign);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	str = "9223372036854655613515613";
	printf("%d \n", ft_atoi(str));
	printf("%d ", atoi(str));
} */
