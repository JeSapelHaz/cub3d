/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:26:49 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/12 13:08:21 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	int	i;

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
	free(data->mapinfo.east_path);
	free(data->mapinfo.north_path);
	free(data->mapinfo.west_path);
	free(data->mapinfo.south_path);
	free(data->mapinfo.file);
	free(data->mapinfo.map);
	data->mapinfo.file = NULL;
}