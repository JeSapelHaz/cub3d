/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:44 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/07 13:25:11 by hdelbecq         ###   ########.fr       */
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
			*(int *)(data->img_addr + pixel) = data->mapinfo.floor_color;
		}
	}
}

// function check if the pixel touch a wall
bool	hit_wall(float px, float py, t_data *data)
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

// check the direction of the raycasting
void	raycast_direction(t_player *player, float angle)
{
	if (angle >= (float)0 && angle < PI / (float)2)
	{
		player->dir_x = 1;
		player->dir_y = 1;
	}
	else if (angle >= PI / (float)2 && angle < PI)
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (angle >= PI && angle < 3 * PI / (float)2)
	{
		player->dir_x = 0;
		player->dir_y = 0;
	}
	else
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
}
