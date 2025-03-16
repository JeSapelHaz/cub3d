/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:44 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/16 17:51:49 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel_to_image(t_data *data, float x, float y, int color)
{
	int		pixel_x;
	int		pixel_y;
	char	*pixel;

	pixel_x = (int)(x + 0.5);
	pixel_y = (int)(y + 0.5);
	if (pixel_x >= 0 && pixel_x < 1920 && pixel_y >= 0 && pixel_y < 1080)
	{
		pixel = data->img_addr + (pixel_y * data->size_line) + (pixel_x
				* (data->bpp / 8));
		*(int *)pixel = color;
	}
}

// Fonction pour effacer l'image (remplir avec du noir)
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
			pixel = (y * data->size_line) + (x * (data->bpp / 8));
			data->img_addr[pixel] = 0;     
			data->img_addr[pixel + 1] = 0; 
			data->img_addr[pixel + 2] = 0; 
		}
	}
}

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

bool	hit_wall(float px, float py, t_data *data)
{
	int	x;
	int	y;

	x = px / TILE_SIZE;
	y = py / TILE_SIZE;
	if (data->mapinfo.map[y][x] == '1')
		return (true);
	return (false);
}

// void draw_line(t_player *player, t_data *data, float start_x, int i)
// {
//     float cos_angle = cos(start_x);
//     float sin_angle = sin(start_x);
//     float ray_x = player->pos_x;
//     float ray_y = player->pos_y;

//     while(!hit_wall(ray_x, ray_y, data))
//     {
// 		put_pixel_to_image(data, ray_x, ray_y, 0xFF0000);
//         ray_x += cos_angle;
//         ray_y += sin_angle;
//     }

// 	float dist = distance(ray_x - player->pos_x, ray_y - player->pos_y);
// 	float height = (TILE_SIZE / dist) * (SCREEN_WIDTH / 2);
// 	int start_y = (SCREEN_HEIGHT - height) / 2;
// 	int end = start_y + height;
// 	while(start_y < end)
// 	{
// 		put_pixel_to_image(data, i, start_y, GREEN);
// 		start_y++;
// 	}
// }


// void	draw_vision(t_data *data)
// {
//     t_player *player = &data->player;
//     float fraction = PI / 3 / SCREEN_WIDTH;
//     float start_x = player->angle - PI / 6;
//     int i = 0;
//     while(i < SCREEN_WIDTH)
//     {
//         draw_line(player, data, start_x, i);
//         start_x += fraction;
//         i++;
//     }
// }

void	draw_line(t_data *data, float x0, float y0, float x1, float y1,
		int color)
{
	float	dx;
	float	dy;
	float	steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	steps = fmax(fabs(dx), fabs(dy));
	x_inc = dx / steps;
	y_inc = dy / steps;
	x = x0;
	y = y0;
	i = 0;
	while (i++ <= steps && x >= 0 && x < SCREEN_WIDTH && y >= 0
		&& y < SCREEN_HEIGHT && !hit_wall(x, y, data))
	{
		put_pixel_to_image(data, x, y, color);
		x += x_inc;
		y += y_inc;
	}
	
}

void	draw_vision(t_data *data)
{
	float	px;
	float	py;
	float	fraction;
	float	start_x;
	int		i;

	px = data->player.pos_x * TILE_SIZE;
	py = data->player.pos_y * TILE_SIZE;
	fraction = (float)FOV * (float)RAD_DEG / (float)SCREEN_WIDTH;
	start_x = data->player.angle;
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		draw_line(data, px, py, px + cos(start_x) * SCREEN_WIDTH, py
			+ sin(start_x) * SCREEN_WIDTH, RED);
		start_x += fraction;
		i++;
	}
}

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
	draw_vision(data);
}
