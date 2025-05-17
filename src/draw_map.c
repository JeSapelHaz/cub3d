/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:35:06 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/18 00:19:55 by hdelbecq         ###   ########.fr       */
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

static void	map_start_draw(t_player *player, int x[2], int y[2])
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

static int	draw_player(t_data *data, int x_pixel, int y_pixel)
{
	if (x_pixel >= (data->player.pos_x * TILE_SIZE) - (TILE_SIZE / 4)
		&& x_pixel <= (data->player.pos_x * TILE_SIZE) + (TILE_SIZE / 4)
		&& y_pixel >= (data->player.pos_y * TILE_SIZE) - (TILE_SIZE / 4)
		&& y_pixel <= (data->player.pos_y * TILE_SIZE) + (TILE_SIZE / 4))
		return (1);
	else
		return (0);
}

static void	draw_mini_map(t_data *data, int x[2], int y[2])
{
	int	x_tmp;
	int	color;
	int	i;
	int	j;

	color = BLACK;
	y[0]--;
	j = 0;
	while (++y[0] < y[1])
	{
		x_tmp = x[0] - 1;
		i = 0;
		while (++x_tmp < x[1])
		{
			if (!draw_player(data, x_tmp, y[0]))
			{
				color = selec_color(data, x_tmp / TILE_SIZE, y[0] / TILE_SIZE);
				put_pixel_to_image(data, i, j, color);
			}
			else
				put_pixel_to_image(data, i, j, RED);
			i++;
		}
		j++;
	}
}

void	draw_2d(t_data *data)
{
	int	x[2];
	int	y[2];

	map_start_draw(&data->player, x, y);
	draw_mini_map(data, x, y);
}
