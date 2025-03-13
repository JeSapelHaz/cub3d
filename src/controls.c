/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/13 17:10:02 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void recharge_image(t_data *data)
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
int	controls(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_A)
	{
		data->player.pos_x -= 0.1;
		recharge_image(data);
	}
	if (keycode == KEY_W)
	{
		data->player.pos_y -= 0.1;
		recharge_image(data);
	}
	if (keycode == KEY_S)
	{
		data->player.pos_y += 0.1;
		recharge_image(data);
	}
	if (keycode == KEY_D)
	{
		data->player.pos_x += 0.1;
		recharge_image(data);
	}
	if (keycode == KEY_LEFT) // Tourner à gauche
{
	data->player.angle -= 0.1;
	if (data->player.angle < 0)
		data->player.angle += 2 * 180;
	recharge_image(data);
}
if (keycode == KEY_RIGHT) // Tourner à droite
{
	data->player.angle += 0.1;
	if (data->player.angle > 2 * 180)
		data->player.angle -= 2 * 180;
	recharge_image(data);
}
	return (0);
}
