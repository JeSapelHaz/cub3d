/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/13 18:24:34 by hbutt            ###   ########.fr       */
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
int	actions(t_data *data)
{
	if (data->keyinfo.press_a)
	{
		data->player.pos_x -= 0.1;
		recharge_image(data);
	}
	if (data->keyinfo.press_w)
	{
		data->player.pos_y -= 0.1;
		recharge_image(data);
	}
	if (data->keyinfo.press_s)
	{
		data->player.pos_y += 0.1;
		recharge_image(data);
	}
	if (data->keyinfo.press_d)
	{
		data->player.pos_x += 0.1;
		recharge_image(data);
	}
	if (data->keyinfo.press_left) // Tourner à gauche
	{
		data->player.angle -= 0.1;
		if (data->player.angle < 0)
			data->player.angle += 2 * 180;
		recharge_image(data);
	}
	if (data->keyinfo.press_right) // Tourner à droite
	{
		data->player.angle += 0.1;
		if (data->player.angle > 2 * 180)
			data->player.angle -= 2 * 180;
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
