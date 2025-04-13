/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:25:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/04/13 14:22:56 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_mapinfo(t_mapinfo *mapinfo)
{
	int i;

	i = -1;
	mapinfo->ceiling = 0;
	mapinfo->ceiling_color = BLUE;
	mapinfo->floor = 0;
	mapinfo->floor_color = GRAY;
	mapinfo->east_path = 0;
	mapinfo->north_path = 0;
	mapinfo->west_path = 0;
	mapinfo->south_path = 0;
	mapinfo->map_height = 0;
	mapinfo->file = NULL;
	mapinfo->map = NULL;
	mapinfo->copy_map = NULL;
	mapinfo->map_width = 0;
	while (++i < 4)
	{
		mapinfo->texture[i].img = NULL;
		mapinfo->texture[i].img_addr = NULL;
		mapinfo->texture[i].bpp = 0;
		mapinfo->texture[i].size_line = 0;
		mapinfo->texture[i].endian = 0;
	}
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
}