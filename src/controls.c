/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/07 17:02:38 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	recharge_image(t_data *data)
{
	clear_image(data);
	draw_map(data);
	draw_player(data);
	fov(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

static int	in_map(t_data *data, float x, float y)
{
	int	i;
	int	j;

	i = x + 0.5;
	j = y + 0.5;
	if (j >= data->mapinfo.map_height || j < 0
		|| i >= (int)ft_strlen(data->mapinfo.map[j]) || i < 0
		|| data->mapinfo.map[j][i] == '1')
		return (0);
	return (1);
}

static void	change_coord(t_player *player, float next_x, float next_y,
		float next_angle)
{
	player->pos_x = next_x;
	player->pos_y = next_y;
	player->angle = next_angle;
	if (player->pos_y < 1)
		player->pos_y = 1;
	else if ((int)player->pos_y > player->data->mapinfo.map_height - 1)
		player->pos_y = player->data->mapinfo.map_height - 1;
	if (player->pos_x < 1)
		player->pos_x = 1;
	else if ((int)player->pos_x > (int)ft_strlen(player->data->mapinfo.map[(int)next_y])
		- 1)
		player->pos_x = ft_strlen(player->data->mapinfo.map[(int)next_y]);
	fix_angle(player->angle);
	printf("x: %f, y: %f, angle: %f\n", player->pos_x, player->pos_y,
		player->angle);
}

int	actions(t_data *data)
{
	float	next_x;
	float	next_y;
	float	next_angle;
	float	cos_speed;
	float	sin_speed;

	cos_speed = cos(data->player.angle) * SPEED;
	sin_speed = sin(data->player.angle) * SPEED;
	next_x = data->player.pos_x;
	next_y = data->player.pos_y;
	next_angle = data->player.angle;
	if (data->keyinfo.press_a && in_map(data, next_x + sin_speed, next_y
			- cos_speed))
	{
		next_x += sin_speed;
		next_y -= cos_speed;
	}
	if (data->keyinfo.press_d && in_map(data, next_x - sin_speed, next_y
			+ cos_speed))
	{
		next_x -= sin_speed;
		next_y += cos_speed;
	}
	if (data->keyinfo.press_w && in_map(data, next_x + cos_speed, next_y
			+ sin_speed))
	{
		next_x += cos_speed;
		next_y += sin_speed;
	}
	if (data->keyinfo.press_s && in_map(data, next_x - cos_speed, next_y
			- sin_speed))
	{
		next_x -= cos_speed;
		next_y -= sin_speed;
	}
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
