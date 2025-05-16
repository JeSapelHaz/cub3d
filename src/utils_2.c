/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:23:32 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 15:52:43 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_trailing_spaces(const char *str)
{
	int	len;
	int	count;

	if (!str)
		return (0);
	len = ft_strlen(str) - 1;
	count = 0;
	while (len >= 0 && (str[len] == ' ' || str[len] == '\n'))
	{
		count++;
		len--;
	}
	return (count);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_file_and_map(t_mapinfo *mapinfo)
{
	free_split(mapinfo->file);
	mapinfo->file = NULL;
	free_split(mapinfo->map);
	mapinfo->map = NULL;
	free_split(mapinfo->copy_map);
	mapinfo->copy_map = NULL;
}

int	clean_exit(t_data *data)
{
	free_data(data);
	exit(0);
}
