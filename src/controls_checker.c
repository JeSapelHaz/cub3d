/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:36:57 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/05/25 02:09:52 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_pressed(t_data *data)
{
	if (data->keyinfo.press_a || data->keyinfo.press_w || data->keyinfo.press_s
		|| data->keyinfo.press_d || data->keyinfo.press_left
		|| data->keyinfo.press_right)
		return (1);
	return (0);
}

void	move_down(t_data *data, t_player *player, float cos_speed,
		float sin_speed)
{
	t_mapinfo	map;

	map = data->mapinfo;
	if (data->keyinfo.press_s)
	{
		if (map.copy_map[(int)(player->pos_y + sin_speed)][(int)(player->pos_x
				- cos_speed)] == '2')
		{
			player->pos_y += sin_speed;
			player->pos_x -= cos_speed;
		}
		else if (map.copy_map[(int)(player->pos_y
				+ sin_speed)][(int)(player->pos_x)] == '2')
			player->pos_y += sin_speed;
		else if (map.copy_map[(int)(player->pos_y)][(int)(player->pos_x
				- cos_speed)] == '2')
			player->pos_x -= cos_speed;
	}
}

void	move_up(t_data *data, t_player *player, float cos_speed,
		float sin_speed)
{
	t_mapinfo	map;

	map = data->mapinfo;
	if (data->keyinfo.press_w)
	{
		if (map.copy_map[(int)(player->pos_y - sin_speed)][(int)(player->pos_x
				+ cos_speed)] == '2')
		{
			player->pos_y -= sin_speed;
			player->pos_x += cos_speed;
		}
		else if (map.copy_map[(int)(player->pos_y
				- sin_speed)][(int)(player->pos_x)] == '2')
			player->pos_y -= sin_speed;
		else if (map.copy_map[(int)(player->pos_y)][(int)(player->pos_x
				+ cos_speed)] == '2')
			player->pos_x += cos_speed;
	}
}

void	move_right(t_data *data, t_player *player, float cos_speed,
		float sin_speed)
{
	t_mapinfo	map;

	map = data->mapinfo;
	if (data->keyinfo.press_d)
	{
		if (map.copy_map[(int)(player->pos_y - cos_speed)][(int)(player->pos_x
				- sin_speed)] == '2')
		{
			player->pos_y -= cos_speed;
			player->pos_x -= sin_speed;
		}
		else if (map.copy_map[(int)(player->pos_y
				- cos_speed)][(int)(player->pos_x)] == '2')
			player->pos_y -= cos_speed;
		else if (map.copy_map[(int)(player->pos_y)][(int)(player->pos_x
				- sin_speed)] == '2')
			player->pos_x -= sin_speed;
	}
}

void	move_left(t_data *data, t_player *player, float cos_speed,
		float sin_speed)
{
	t_mapinfo	map;

	map = data->mapinfo;
	if (data->keyinfo.press_a)
	{
		if (map.copy_map[(int)(player->pos_y + cos_speed)][(int)(player->pos_x
				+ sin_speed)] == '2')
		{
			player->pos_y += cos_speed;
			player->pos_x += sin_speed;
		}
		else if (map.copy_map[(int)(player->pos_y
				+ cos_speed)][(int)(player->pos_x)] == '2')
			player->pos_y += cos_speed;
		else if (map.copy_map[(int)(player->pos_y)][(int)(player->pos_x
				+ sin_speed)] == '2')
			player->pos_x += sin_speed;
	}
}
