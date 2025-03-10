/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:25:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/10 14:51:22 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->ceiling = 0;
	mapinfo->floor = 0;
	mapinfo->east_path = 0;
	mapinfo->north_path = 0;
	mapinfo->west_path = 0;
	mapinfo->south_path = 0;
	mapinfo->map_height = 0;
	mapinfo->file = NULL;
	mapinfo->map = NULL;
}

static void init_player(t_player *player)
{
	player->pos_x = 0;
    player->pos_y = 0;
    player->dir_x = 0;  // Direction du joueur
    player->dir_y = 0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->win_height = SCREEN_HEIGHT;
	data->win_width = SCREEN_WIDTH;
	init_mapinfo(&data->mapinfo);
	init_player(&data->player);
}
