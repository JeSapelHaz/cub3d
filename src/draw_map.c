/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:35:06 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/17 18:33:51 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	selec_color(t_data *data, int x_map, int y_map)
{
	int	color;

	if (y_map < 0 || y_map >= data->mapinfo.map_height || x_map < 0
		|| x_map >= (int)ft_strlen(data->mapinfo.map[y_map]))
		return (-1);
	if (data->mapinfo.map[y_map][x_map] == '1')
		color = WHITE;
	else if (data->mapinfo.map[y_map][x_map] == '0'
		|| data->mapinfo.map[y_map][x_map] == '2'
		|| data->mapinfo.map[y_map][x_map] == 'N'
		|| data->mapinfo.map[y_map][x_map] == 'S'
		|| data->mapinfo.map[y_map][x_map] == 'E'
		|| data->mapinfo.map[y_map][x_map] == 'W')
		color = BLACK;
	else
		return (-1);
	return (color);
}

static void	mini_map_start(t_player *player, int x[2], int y[2])
{
	x[0] = (int)(player->pos_x * TILE_SIZE) - (TILE_SIZE * 5);
	y[0] = (int)(player->pos_y * TILE_SIZE) - (TILE_SIZE * 5);
	if (x[0] < 0.0f)
	{
		x[1] = (int)(player->pos_x * TILE_SIZE) + (TILE_SIZE * 5) - x[0];
		if (x[1] > SCREEN_WIDTH)
			x[1] = SCREEN_WIDTH;
		x[0] = 0;
	}
	else
		x[1] = (int)(player->pos_x * TILE_SIZE) + (TILE_SIZE * 5);
	if (y[0] < 0.0f)
	{
		y[1] = (int)(player->pos_y * TILE_SIZE) + (TILE_SIZE * 5) - y[0];
		if (y[1] > SCREEN_HEIGHT)
			y[1] = SCREEN_HEIGHT;
		y[0] = 0;
	}
	else
		y[1] = (int)(player->pos_y * TILE_SIZE) + (TILE_SIZE * 5);
}

static void	draw_mini_map(t_data *data)
{
	int	x[2];
	int	y[2];
	int	x_tmp;
	int	color;

	color = BLACK;
	mini_map_start(&data->player, x, y);
	y[0]--;
	while (++y[0] < y[1])
	{
		x_tmp = x[0] - 1;
		while (++x_tmp < x[1])
		{
			color = selec_color(data, x_tmp / TILE_SIZE, y[0] / TILE_SIZE);
			put_pixel_to_image(data, x_tmp, y[0], color);
		}
	}
}

// dessine un carré pour le joueur
static void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	player_size;

	player_size = TILE_SIZE / 4;
	i = -player_size / 2;
	while (++i < player_size / 2)
	{
		j = -player_size / 2;
		while (++j < player_size / 2)
		{
			put_pixel_to_image(data, data->player.pos_x * TILE_SIZE + i,
				data->player.pos_y * TILE_SIZE + j, RED);
		}
	}
}

void	draw_2d(t_data *data)
{
	draw_mini_map(data);
	draw_player(data);
}
