/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:25:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 23:19:48 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_texture(t_mapinfo *mapinfo)
{
	mapinfo->textures[NORTH].img = NULL;
	mapinfo->textures[SOUTH].img = NULL;
	mapinfo->textures[EAST].img = NULL;
	mapinfo->textures[WEST].img = NULL;
	mapinfo->textures[NORTH].img_addr = NULL;
	mapinfo->textures[SOUTH].img_addr = NULL;
	mapinfo->textures[EAST].img_addr = NULL;
	mapinfo->textures[WEST].img_addr = NULL;
}

static void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->ceiling = 0;
	mapinfo->ceiling_color = BLUE;
	mapinfo->floor = 0;
	mapinfo->floor_color = GRAY;
	mapinfo->textures[NORTH].path = 0;
	mapinfo->textures[SOUTH].path = 0;
	mapinfo->textures[EAST].path = 0;
	mapinfo->textures[WEST].path = 0;
	mapinfo->map_height = 0;
	mapinfo->file = NULL;
	mapinfo->map = NULL;
	mapinfo->copy_map = NULL;
	mapinfo->map_width = 0;
}

static void	init_player(t_player *player, t_data *data)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->angle = 0;
	player->data = data;
}

static void	init_keys(t_keyinfo *keyinfo)
{
	keyinfo->press_a = 0;
	keyinfo->press_d = 0;
	keyinfo->press_w = 0;
	keyinfo->press_s = 0;
	keyinfo->press_right = 0;
	keyinfo->press_left = 0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->img_addr = NULL;
	data->win_height = SCREEN_HEIGHT;
	data->win_width = SCREEN_WIDTH;
	init_mapinfo(&data->mapinfo);
	init_player(&data->player, data);
	init_keys(&data->keyinfo);
	init_texture(&data->mapinfo);
}