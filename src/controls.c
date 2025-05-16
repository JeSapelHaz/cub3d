/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 23:51:59 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	change_coord(t_player *player, float next_x, float next_y,
		float next_angle)
{
	int	pos_x;
	int	pos_y;

	player->pos_x = next_x;
	player->pos_y = next_y;
	player->angle = fix_angle(next_angle);
	pos_y = ceilf(player->pos_y);
	pos_x = ceilf(player->pos_x);
	if (player->data->mapinfo.map[pos_y][(int)player->pos_x] == '1'
		&& (float)pos_y - player->pos_y < 0.3f)
		player->pos_y = (float)pos_y - 0.3f;
	if (player->data->mapinfo.map[(int)player->pos_y][pos_x] == '1'
		&& (float)pos_x - player->pos_x < 0.3f)
		player->pos_x = (float)pos_x - 0.3f;
	pos_y = floorf(player->pos_y) - 1;
	pos_x = floorf(player->pos_x) - 1;
	if (player->data->mapinfo.map[pos_y][(int)player->pos_x] == '1'
		&& player->pos_y - (float)pos_y < 1.3f)
		player->pos_y = (float)pos_y + 1.3f;
	if (player->data->mapinfo.map[(int)player->pos_y][pos_x] == '1'
		&& player->pos_x - (float)pos_x < 1.3f)
		player->pos_x = (float)pos_x + 1.3f;
}

void	movement_pressed(t_data *data, t_player *player, float cos_speed,
		float sin_speed)
{
	if (data->keyinfo.press_a)
	{
		player->pos_x += sin_speed;
		player->pos_y += cos_speed;
	}
	if (data->keyinfo.press_d)
	{
		player->pos_x -= sin_speed;
		player->pos_y -= cos_speed;
	}
	if (data->keyinfo.press_w)
	{
		player->pos_x += cos_speed;
		player->pos_y -= sin_speed;
	}
	if (data->keyinfo.press_s)
	{
		player->pos_x -= cos_speed;
		player->pos_y += sin_speed;
	}
	if (data->keyinfo.press_left)
		player->angle -= ROTATE_SPEED;
	if (data->keyinfo.press_right)
		player->angle += ROTATE_SPEED;
}

int	actions(t_data *data)
{
	float		cos_speed;
	float		sin_speed;
	t_player	*player;

	if (is_pressed(data))
	{
		player = &data->player;
		cos_speed = cos(player->angle) * SPEED;
		sin_speed = sin(player->angle) * SPEED;
		movement_pressed(data, player, cos_speed, sin_speed);
		change_coord(&data->player, player->pos_x, player->pos_y,
			player->angle);
		load_image(data);
	}
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
	{
		free_data(data);
		exit(0);
	}
	if (key == KEY_A)
		data->keyinfo.press_a = 1;
	if (key == KEY_W)
		data->keyinfo.press_w = 1;
	if (key == KEY_S)
		data->keyinfo.press_s = 1;
	if (key == KEY_D)
		data->keyinfo.press_d = 1;
	if (key == KEY_LEFT)
		data->keyinfo.press_left = 1;
	if (key == KEY_RIGHT)
		data->keyinfo.press_right = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_A)
		data->keyinfo.press_a = 0;
	if (key == KEY_W)
		data->keyinfo.press_w = 0;
	if (key == KEY_S)
		data->keyinfo.press_s = 0;
	if (key == KEY_D)
		data->keyinfo.press_d = 0;
	if (key == KEY_LEFT)
		data->keyinfo.press_left = 0;
	if (key == KEY_RIGHT)
		data->keyinfo.press_right = 0;
	return (0);
}
