/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:26:49 by hbutt             #+#    #+#             */
/*   Updated: 2025/02/26 15:47:47 by hbutt            ###   ########.fr       */
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
	free(data->mapinfo.file);
	data->mapinfo.file = NULL;
}
