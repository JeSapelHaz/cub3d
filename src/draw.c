#include "../includes/cub3d.h"

// Fonction pour dessiner un pixel
void	draw_pixel(t_data *data, int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel = (y * data->size_line) + (x * (data->bpp / 8));
		data->addr[pixel] = color & 0xFF;
		data->addr[pixel + 1] = (color >> 8) & 0xFF;
		data->addr[pixel + 2] = (color >> 16) & 0xFF;
	}
}

// Fonction pour effacer l'image (remplir avec du noir)
void	clear_image(t_data *data)
{
	int	pixel;
	int y;
    int x;

    y = -1;
    while (++y < SCREEN_HEIGHT)
	{
        	x = -1;
		while (++x < SCREEN_WIDTH)
		{
			pixel = (y * data->size_line) + (x * (data->bpp / 8));
			data->addr[pixel] = 0;     // R
			data->addr[pixel + 1] = 0; // G
			data->addr[pixel + 2] = 0; // B
		}
	}
}

void drawMap2D(t_data* data)
{
	int x_map;
	int x_screen;
	int y_map;
	int y_screen;
	int color;
	int i;
	int j;
	
	y_map = -1;
	while (++y_map < data->mapinfo.map_height)
	{
	x_map = -1;
	while(++x_map < data->mapinfo.map_width)
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
				draw_pixel(data, x_screen + i, y_screen + j, color);
			}
		}
	}
	}
}

