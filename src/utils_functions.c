/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:12:56 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/07 13:25:11 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

char	**copy_2d_map(char **map)
{
	int		height;
	char	**new_map;

	height = 0;
	while (map[height])
		height++;
	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	for (int i = 0; i < height; i++)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
	}
	new_map[height] = NULL;
	return (new_map);
}

int	convert_color(char *str)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == ',')
		str++;
	else
		return (printf("ERROR RGB syntax is RRR,GGG,BBB\n"), -1);
	g = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == ',')
		str++;
	else
		return (printf("ERROR RGB syntax is RRR,GGG,BBB\n"), -1);
	b = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0 || *str)
		return (printf("ERROR RGB syntax is RRR,GGG,BBB\n"), -1);
	return ((r << 16) + (g << 8) + b);
}

float	distance(float x, float y)
{
	return (sqrt((x * x) + (y * y)));
}
