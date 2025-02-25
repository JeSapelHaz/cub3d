/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:11:27 by hbutt             #+#    #+#             */
/*   Updated: 2025/02/25 13:06:20 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* va libérer la mémoire allouée à la chaine pointée par str
	+ va mettre le pointer str à NULL pour eéviter l'accès aà une
	zone de mémoire déjà libérée (segfault)	*/
char	*ft_free_all(char **str)
{
	free(*str);
	*str = NULL;
	return (0);
}

/* booleen qui renvoie 1 si la string ne contient pas de '\n' sinon 0 */
int	ft_no_nl_next(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

/* va concatener les 2 string et renvoyer la nouvelle string en ayant
	préalablement allouée la mémoire avec la bonne taille */
char	*ft_strjoin_gnl(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*join;

	size = ft_strlen(str1) + ft_strlen(str2);
	if (size == 0)
		return (ft_free_all(&str1));
	join = malloc(sizeof(char) * (size + 1));
	if (!join)
		return (ft_free_all(&str1));
	i = 0;
	j = 0;
	if (str1)
	{
		while (str1[i] && j < size)
			join[j++] = str1[i++];
	}
	i = 0;
	while (str2[i] && j < size)
		join[j++] = str2[i++];
	join[j] = '\0';
	free(str1);
	return (join);
}
