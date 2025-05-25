/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/25 14:59:59 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	actions(t_data *data)
{
	float		cos_speed;
	float		sin_speed;
	t_player	*player;

	if (key_pressed(data))
	{
		player = &data->player;
		cos_speed = cos(player->angle) * SPEED;
		sin_speed = sin(player->angle) * SPEED;
		move_down(data, player, cos_speed, sin_speed);
		move_up(data, player, cos_speed, sin_speed);
		move_right(data, player, cos_speed, sin_speed);
		move_left(data, player, cos_speed, sin_speed);
		if (data->keyinfo.press_left)
			player->angle -= ROTATE_SPEED;
		if (data->keyinfo.press_right)
			player->angle += ROTATE_SPEED;
		player->angle = fix_angle(player->angle);
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
