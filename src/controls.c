/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:50:36 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/11 16:24:13 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int movement(int keycode, void *param)
{
    t_data *data = (t_data *)param;
    t_player *player = &data->player;

    if (keycode == 65361)  // Left arrow
	{
        player->angle = FixAng(player->angle + ROTATE_SPEED);
        player->dir_x = cos(degToRad(player->angle));
        player->dir_y = -sin(degToRad(player->angle));
    }
    if (keycode == 65363) // Right arrow
	{ 
        player->angle = FixAng(player->angle - ROTATE_SPEED);
        player->dir_x = cos(degToRad(player->angle));
        player->dir_y = -sin(degToRad(player->angle));
    }
    if (keycode == 65362) // Up arrow
	{ 
        player->pos_x += player->dir_x * MOVEMENT_SPEED;
        player->pos_y += player->dir_y * MOVEMENT_SPEED;
    }
    if (keycode == 65364) // Down arrow
	{
        player->pos_x -= player->dir_x * MOVEMENT_SPEED;
        player->pos_y -= player->dir_y * MOVEMENT_SPEED;
    }
    // Effacer l'image avant de redessiner
    clearImage(data);
    // Redessiner la carte, le joueur et les rayons
    drawMap2D(data);
    drawPlayer2D(data, player);
    drawRays2D(data, player);
    // Mettre à jour la fenêtre
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int	controls(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
