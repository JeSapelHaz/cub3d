/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/16 15:59:19 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	recharge_image(t_data *data)
{
	printf("Nouvelle position du joueur : %f, %f\n", data->player.pos_x,
		data->player.pos_y);
	clear_image(data);
	// efface l'image précédente
	draw_map(data);
	// redessine la map
	draw_player(data);
	// redessine le joueur
	draw_vision(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	// met à jour l'image dans la fenêtre
}

static int	in_map(t_data *data, float next_x, float next_y)
{
	int	i;
	int	j;

	i = (int)(next_x);
	j = (int)(next_y);
	if (data->mapinfo.copy_map[j][i] == '1')
		return (0);
	return (1);
}

int	actions(t_data *data)
{
	float	next_x;
	float	next_y;

	next_x = data->player.pos_x;
	next_y = data->player.pos_y;
	if (data->keyinfo.press_a)
		next_x -= 0.1;
	if (data->keyinfo.press_w)
		next_y -= 0.1;
	if (data->keyinfo.press_s)
		next_y += 0.1;
	if (data->keyinfo.press_d)
		next_x += 0.1;
	if (in_map(data, next_x, next_y))
	{
		data->player.pos_x = next_x;
		data->player.pos_y = next_y;
		recharge_image(data);
	}
	if (data->keyinfo.press_left)
	{
		data->player.angle -= 0.1;
		if (data->player.angle < 0)
			data->player.angle += 360;
		recharge_image(data);
	}
	if (data->keyinfo.press_right)
	{
		data->player.angle += 0.1;
		if (data->player.angle > 360)
			data->player.angle -= 360;
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
