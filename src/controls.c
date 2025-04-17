/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/04/17 17:36:43 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	recharge_image(t_data *data)
{
	clear_image(data); // clear image necessary ?
	// draw_map(data);
	draw_player(data);
	draw_vision(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

static int	in_map(t_data *data, double x, double y)
{
	int	i;
	int	j;

	i = round(x);
	j = round(y);
	if (j >= data->mapinfo.map_height || j < 0
		|| i >= (int)ft_strlen(data->mapinfo.map[j]) || i < 0
		|| data->mapinfo.map[j][i] == '1')
		return (0);
	return (1);
}

static void	change_coord(t_player *player, double next_x, double next_y,
		double next_angle)
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
	if (player->angle < 0)
		player->angle += 2 * PI;
	if (player->angle >= 2 * PI)
		player->angle -= 2 * PI;
	printf("x: %f, y: %f, angle: %f\n", player->pos_x, player->pos_y,
		player->angle);
}

int	actions(t_data *data)
{
	double	next_x;
	double	next_y;
	double	next_angle;
	double	cos_speed;
	double	sin_speed;

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
		next_angle -= (double)ROTATE_SPEED;
	if (data->keyinfo.press_right)
		next_angle += (double)ROTATE_SPEED;
	if (next_x != data->player.pos_x || next_y != data->player.pos_y
		|| next_angle != data->player.angle)
		change_coord(&data->player, next_x, next_y, next_angle);
	recharge_image(data);
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
