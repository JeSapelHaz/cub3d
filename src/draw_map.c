/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:35:06 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 19:35:07 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// function check if the pixel touch a wall
bool	hit_wall_map(float px, float py, t_data *data)
{
	int	x;
	int	y;

	x = (px / (float)TILE_SIZE) + 0.5;
	y = (py / (float)TILE_SIZE) + 0.5;
	if (y >= data->mapinfo.map_height || y < 0
		|| x >= (int)ft_strlen(data->mapinfo.map[y]) || x < 0
		|| data->mapinfo.map[y][x] == '1')
		return (true);
	return (false);
}
void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = abs(x2 - x1);
	dy = -abs(y2 - y1);
	err = dx + dy;
	while (1)
	{
		if (hit_wall_map(x1, y1, data))
			break ;
		put_pixel_to_image(data, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += (x1 < x2 ? 1 : -1);
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += (y1 < y2 ? 1 : -1);
		}
	}
}

// draw mini map
void	draw_map(t_data *data)
{
	int	x_map;
	int	y_map;
	int	x_screen;
	int	y_screen;
	int	i;
	int	j;
	int	color;

	y_map = -1;
	while (++y_map < data->mapinfo.map_height)
	{
		x_map = -1;
		while (++x_map < (int)ft_strlen(data->mapinfo.map[y_map]))
		{
			if (data->mapinfo.map[y_map][x_map] == '1')
				color = WHITE;
			else
				color = BLACK;
			y_screen = y_map * TILE_SIZE;
			x_screen = x_map * TILE_SIZE;
			i = -1;
			while (++i < TILE_SIZE)
			{
				j = -1;
				while (++j < TILE_SIZE)
					put_pixel_to_image(data, x_screen + i, y_screen + j, color);
			}
		}
	}
}
// dessine un carré pour le joueur
void	draw_player(t_data *data)
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

// FOV
void	fov(t_data *data)
{
	float start_angle;
	float cos_angle;
	float sin_angle;
	float steps;
	int i;

	start_angle = data->player.angle - degToRad(FOV / 2);
	steps = degToRad(FOV) / SCREEN_WIDTH;
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		cos_angle = cos(start_angle + i * steps);
		sin_angle = sin(start_angle + i * steps);
		draw_line(data, data->player.pos_x * TILE_SIZE, data->player.pos_y
			* TILE_SIZE, (data->player.pos_x + cos_angle) * TILE_SIZE,
			(data->player.pos_y + sin_angle) * TILE_SIZE, GREEN);
	}
}