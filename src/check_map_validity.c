/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:47:57 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/20 19:03:04 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	access_backtrack(t_data *data, int y, int x)
{
	if (y < 0 || y >= data->mapinfo.map_height)
		return (printf("Error : the map is not valid\n"), clean_exit(data));
	if (y + 1 < 0 || y + 1 > data->mapinfo.map_height
		|| !data->mapinfo.copy_map[y])
		return (printf("Error : the map is not valid\n"), clean_exit(data));
	if (y - 1 < 0 || y - 1 > data->mapinfo.map_height
		|| !data->mapinfo.copy_map[y])
		return (printf("Error : the map is not valid\n"), clean_exit(data));
	if (x + 1 < 0 || x + 1 > (int)ft_strlen(data->mapinfo.copy_map[y]))
		return (printf("Error : the map is not valid\n"), clean_exit(data));
	if (x - 1 < 0 || x - 1 > (int)ft_strlen(data->mapinfo.copy_map[y]))
		return (printf("Error : the map is not valid\n"), clean_exit(data));
	if (data->mapinfo.copy_map[y + 1][x] == ' ' || data->mapinfo.copy_map[y
		- 1][x] == ' ')
		return (printf("Error : the map is not valid\n"), clean_exit(data));
	if (data->mapinfo.copy_map[y][x + 1] == ' ' || data->mapinfo.copy_map[y][x
		- 1] == ' ')
		return (printf("Error : the map is not valid\n"), clean_exit(data));
	return (1);
}

static int	move_backtrack(t_data *data, int y, int x)
{
	if (data->mapinfo.copy_map[y][x] != '0')
		return (0);
	return (1);
}

/* Check is the map is valid or not */
void	back_track(t_data *data, int y, int x)
{
	access_backtrack(data, y, x);
	data->mapinfo.copy_map[y][x] = '2';
	if (move_backtrack(data, y + 1, x))
		back_track(data, y + 1, x);
	if (move_backtrack(data, y - 1, x))
		back_track(data, y - 1, x);
	if (move_backtrack(data, y, x + 1))
		back_track(data, y, x + 1);
	if (move_backtrack(data, y, x - 1))
		back_track(data, y, x - 1);
}
