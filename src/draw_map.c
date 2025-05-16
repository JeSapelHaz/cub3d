/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:35:06 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 23:51:39 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	selec_color(t_data *data, int x_map, int y_map)
{
	int	color;

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

// draw mini map
void	draw_map(t_data *data, int x_map, int y_map)
{
	int	x_screen;
	int	i;
	int	j;
	int	y_screen;
	int	color;

	x_map = -1;
	while (++y_map < data->mapinfo.map_height)
	{
		x_map = -1;
		while (++x_map < (int)ft_strlen(data->mapinfo.map[y_map]))
		{
			y_screen = y_map * TILE_SIZE;
			x_screen = x_map * TILE_SIZE;
			color = selec_color(data, x_map, y_map);
			i = -1;
			while (++i < TILE_SIZE && color != -1)
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

void	draw_2d(t_data *data)
{
	int	x_map;
	int	y_map;

	x_map = -1;
	y_map = -1;
	draw_map(data, x_map, y_map);
	draw_player(data);
}
