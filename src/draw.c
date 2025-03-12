/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:44 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/12 15:42:51 by hbutt            ###   ########.fr       */
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
	if (pixel_x >= 0 && pixel_x < 1920 && pixel_y >= 0
		&& pixel_y < 1080)
	{
		pixel = data->img_addr + (pixel_y * data->size_line) + (pixel_x * (data->bpp
					/ 8));
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
			data->img_addr[pixel] = 0;     // R
			data->img_addr[pixel + 1] = 0; // G
			data->img_addr[pixel + 2] = 0; // B
		}
	}
}

void	draw_map(t_data *data)
{
	int	x_map;
	int	x_screen;
	int	y_map;
	int	y_screen;
	int	color;
	int	i;
	int	j;

	y_map = -1;
	while (++y_map < data->mapinfo.map_height)
	{
		x_map = -1;
		while (++x_map < (int)ft_strlen(data->mapinfo.map[y_map])) // change for data->mapinfo.map_width
		{
			if (data->mapinfo.map[y_map][x_map] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			y_screen = y_map * TILE_SIZE;
			x_screen = x_map * TILE_SIZE;
			i = -1;
			while (++i < TILE_SIZE)
			{
				j = -1;
				while (++j < TILE_SIZE)
				{
					if (j % 64 == 0 || i % 64 == 0)
						put_pixel_to_image(data, x_screen + i, y_screen + j, GREEN);
					else
						put_pixel_to_image(data, x_screen + i, y_screen + j, color);
				}
			}
		}
	}
}
