/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:21:52 by hbutt             #+#    #+#             */
/*   Updated: 2024/04/23 17:58:47 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			nb++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static void	ft_putstr(char *split, char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		split[i] = str[i];
		i++;
	}
	split[i] = '\0';
}

static int	ft_put_in_split(char **split, char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j])
				j++;
			split[k] = malloc(sizeof(char) * j + 1);
			if (!split[k])
				return (0);
			ft_putstr(split[k], str + i, c);
			i += j;
			k++;
		}
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	size_t	size;
	int		k;

	if (!str)
		return (NULL);
	size = count_words(str, c);
	split = malloc((size + 1) * sizeof(char *));
	if (!split)
		return (0);
	k = ft_put_in_split(split, str, c);
	if (k == 0)
	{
		while (split[k])
		{
			free(split[k]);
			k++;
		}
		free(split);
		return (0);
	}
	split[size] = 0;
	return (split);
}

/* #include <stdio.h>
int	main(void)
{
	char *str = "kkkk ca kkkkkk va kkkkk
	wjhqbdkw kcjnckejbcmxmnmzjbfelfjnmmnkkk";
	c = 'k';
	split = ft_split(str, c);
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
} */