/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:26:49 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 12:03:57 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	int i;

	i = 0;
	if (!data || !data->mapinfo.file)
		return ;
	while (data->mapinfo.file[i])
	{
		free(data->mapinfo.file[i]);
		i++;
	}
	i = 0;
	while (data->mapinfo.map[i])
	{
		free(data->mapinfo.map[i]);
		i++;
	}
	free(data->mapinfo.textures[EAST].path);
	free(data->mapinfo.textures[NORTH].path);
	free(data->mapinfo.textures[WEST].path);
	free(data->mapinfo.textures[SOUTH].path);

	free(data->mapinfo.file);
	free(data->mapinfo.map);
	data->mapinfo.file = NULL;
}