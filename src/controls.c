/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/20 22:12:59 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	recharge_image(t_data *data)
{
	clear_image(data);
	// draw_map(data);
	draw_player(data);
	draw_vision(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

static int	in_map(t_data *data, float x, float y)
{
	int	i;
	int	j;

	i = (int)(x + 0.5);
	j = (int)(y + 0.5);
	if (j >= SCREEN_HEIGHT || i >= SCREEN_WIDTH
		|| data->mapinfo.map[j][i] == '1')
		return (0);
	return (1);
}

static void	change_coord(t_player *player, float next_x, float next_y,
		float next_angle)
{
	player->pos_x = next_x;
	if (player->pos_x < 1)
		player->pos_x = 1;
	player->pos_y = next_y;
	if (player->pos_y < 1)
		player->pos_y = 1;
	player->angle = next_angle;
	if (player->angle < 0)
		player->angle += 2 * PI;
	if (player->angle >= 2 * PI)
		player->angle -= 2 * PI;
}

int	actions(t_data *data)
{
	float	next_x;
	float	next_y;
	float	next_angle;

	next_x = data->player.pos_x;
	next_y = data->player.pos_y;
	next_angle = data->player.angle;
	if (data->keyinfo.press_a && in_map(data, next_x, next_y))
		next_x -= (float)SPEED;
	if (data->keyinfo.press_w && in_map(data, next_x, next_y))
		next_y -= (float)SPEED;
	if (data->keyinfo.press_s && in_map(data, next_x, next_y))
		next_y += (float)SPEED;
	if (data->keyinfo.press_d && in_map(data, next_x, next_y))
		next_x += (float)SPEED;
	if (data->keyinfo.press_left)
		next_angle -= (float)ROTATE_SPEED;
	if (data->keyinfo.press_right)
		next_angle += (float)ROTATE_SPEED;
	if (next_x != data->player.pos_x || next_y != data->player.pos_y
		|| next_angle != data->player.angle)
	{
		change_coord(&data->player, next_x, next_y, next_angle);
		recharge_image(data);
	}
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
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
