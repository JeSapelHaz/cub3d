/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:35:06 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/25 17:20:23 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	selec_color(t_data *data, int x_map, int y_map)
{
	int	color;

	if (y_map < 0 || y_map >= data->mapinfo.map_height || x_map < 0
		|| x_map >= (int)ft_strlen(data->mapinfo.map[y_map]))
		return (-1);
	if (data->mapinfo.map[y_map][x_map] == '1')
		color = MAP_WALL;
	else if (data->mapinfo.copy_map[y_map][x_map] == '2')
		color = MAP_EMPTY;
	else
		return (-1);
	return (color);
}

static void	map_start_draw(t_player *player, int x[2], int y[2])
{
	int	map_size;

	map_size = TILE_SIZE * SIZE_IN_TILE;
	x[0] = (int)(player->pos_x * TILE_SIZE) - ((float)map_size / 2.0f);
	x[1] = (int)(player->pos_x * TILE_SIZE) + ((float)map_size / 2.0f);
	y[0] = (int)(player->pos_y * TILE_SIZE) - ((float)map_size / 2.0f);
	y[1] = (int)(player->pos_y * TILE_SIZE) + ((float)map_size / 2.0f);
	if (x[0] < 0)
	 x[0] = 0;
	if (y[0] < 0)
	 y[0] = 0;
}

static int	draw_player(t_data *data, int x_pixel, int y_pixel)
{
	if (x_pixel >= (data->player.pos_x * TILE_SIZE) - (TILE_SIZE / 8)
		&& x_pixel <= (data->player.pos_x * TILE_SIZE) + (TILE_SIZE / 8)
		&& y_pixel >= (data->player.pos_y * TILE_SIZE) - (TILE_SIZE / 8)
		&& y_pixel <= (data->player.pos_y * TILE_SIZE) + (TILE_SIZE / 8))
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

	j = Y_GAP;
	--y[0];
	while (++y[0] < y[1])
	{
		x_tmp = x[0] - 1;
		i = X_GAP;
		while (++x_tmp < x[1])
		{
			if (draw_player(data, x_tmp, y[0]))
				put_pixel_to_image(data, i, j, RED);
			else
			{
				color = selec_color(data, x_tmp / TILE_SIZE, y[0] / TILE_SIZE);
				if (color != -1)
					put_pixel_to_image(data, i, j, color);
			}
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
