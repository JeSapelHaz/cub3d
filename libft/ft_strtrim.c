/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:13:29 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/19 15:28:58 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_null(void)
{
	char	*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

/* supprime les la derniere et la premiere occurence de chaque carac dans set */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	str = NULL;
	if (!s1 || !set)
		return (NULL);
	if (!s1[0])
		return (ft_null());
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]))
		start++;
	if (end < start)
		return (ft_strdup(s1 + end + 1));
	while (ft_strrchr(set, s1[end]))
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (0);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}

/* #include <stdio.h>

int	main(void)
{
	char const s1[20] = "";
	char const set[2] = "";
	printf("%s", ft_strtrim(s1, set));
} */