/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:44 by hbutt             #+#    #+#             */
/*   Updated: 2025/04/13 13:55:44 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// function to replace a pixel color
void	put_pixel_to_image(t_data *data, int pixel_x, int pixel_y, int color)
{
	char	*pixel;

	if (pixel_x >= 0 && pixel_x < SCREEN_WIDTH && pixel_y >= 0
		&& pixel_y < SCREEN_HEIGHT)
	{
		pixel = data->img_addr + (pixel_y * data->size_line) + (pixel_x
				* (data->bpp >> 3));
		*(int *)pixel = color;
	}
}

// function to replace all pixel by black
void	clear_image(t_data *data)
{
	int	pixel;
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			pixel = (y * data->size_line) + (x * (data->bpp >> 3));
			data->img_addr[pixel] = 0;
			data->img_addr[pixel + 1] = 0;
			data->img_addr[pixel + 2] = 0;
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

// function check if the pixel touch a wall
bool	hit_wall(double px, double py, t_data *data)
{
	int	x;
	int	y;

	x = round(px);
	y = round(py);
	if (y >= data->mapinfo.map_height || y < 0
		|| x >= (int)ft_strlen(data->mapinfo.map[y]) || x < 0
		|| data->mapinfo.map[y][x] == '1')
		return (true);
	return (false);
}
// draw on the y axis
void	draw_y(t_player *player, t_data *data, double angle, int x)
{
	double	cos_angle;
	double	sin_angle;
	double	ray_x;
	double	ray_y;
	double	dist;
	int		line_height;
	int		draw_start;
	int		wall_start;
	int		wall_end;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	ray_x = player->pos_x;
	ray_y = player->pos_y;
	while (!hit_wall(ray_x, ray_y, data))
	{
		ray_x += cos_angle * 0.01;
		ray_y += sin_angle * 0.01;
	}
	dist = distance(ray_x - player->pos_x, ray_y - player->pos_y);
	dist *= cos(player->angle - angle);
	line_height = round((double)SCREEN_HEIGHT / dist);
	wall_start = (SCREEN_HEIGHT >> 1) - (line_height >> 1);
	wall_end = (SCREEN_HEIGHT >> 1) + (line_height >> 1);
	draw_start = 0;
	while (draw_start < SCREEN_HEIGHT)
	{
		if (draw_start < wall_start)
			put_pixel_to_image(data, x, draw_start,
				data->mapinfo.ceiling_color);
		else if (draw_start < wall_end)
			put_pixel_to_image(data, x, draw_start, RED);
		else
			put_pixel_to_image(data, x, draw_start, data->mapinfo.floor_color);
		draw_start++;
	}
}

// function to draw vison of player (draw FOV)
void	draw_vision(t_data *data)
{
	int		screen_x;
	double	ray_angle;
	double	add_angle;

	// vision decay
	ray_angle = data->player.angle - ((double)FOV / 2.0f) * (PI / 180.0f);
	add_angle = ((double)FOV * (PI / 180.0f)) / (double)SCREEN_WIDTH;
	screen_x = 0;
	while (screen_x < SCREEN_WIDTH)
	{
		draw_y(&data->player, data, ray_angle, screen_x);
		ray_angle += add_angle;
		screen_x++;
	}
}

// function of merda
void	draw_player(t_data *data)
{
	t_player	*player;

	player = &data->player;
	player->height = TILE_SIZE / 2; // useless enlever dans le .h
	draw_vision(data);
}
