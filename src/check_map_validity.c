/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:47:57 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 23:19:30 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Check is the map is valid or not */
void	back_track(t_data *data, int y, int x, int *flag)
{
	if (*flag == 0 && (data->mapinfo.copy_map[y][x] == ' ' || (y == 0
				&& data->mapinfo.copy_map[y][x] != '1')
			|| (y == data->mapinfo.map_height - 1
				&& data->mapinfo.copy_map[y][x] != '1') || (x == 0
				&& data->mapinfo.copy_map[y][x] != '1')
			|| (x == (int)ft_strlen(data->mapinfo.copy_map[y]) - 1
				&& data->mapinfo.copy_map[y][x] != '1')))
		*flag = 1;

	data->mapinfo.copy_map[y][x] = '2';
	if (y < data->mapinfo.map_height - 1 && data->mapinfo.copy_map[y
		+ 1][x] != '1' && data->mapinfo.copy_map[y + 1][x] != '2')
		back_track(data, y + 1, x, flag);
	if (y > 0 && data->mapinfo.copy_map[y - 1][x] != '1'
		&& data->mapinfo.copy_map[y - 1][x] != '2')
		back_track(data, y - 1, x, flag);
	if (data->mapinfo.copy_map[y][x + 1] != '\0' && data->mapinfo.copy_map[y][x
		+ 1] != '\0' && data->mapinfo.copy_map[y][x + 1] != '1'
		&& data->mapinfo.copy_map[y][x + 1] != '2')
		back_track(data, y, x + 1, flag);
	if (x > 0 && data->mapinfo.copy_map[y][x - 1] != '1'
		&& data->mapinfo.copy_map[y][x - 1] != '2')
		back_track(data, y, x - 1, flag);
}