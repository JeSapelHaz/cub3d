#include "../includes/cub3d.h"

// draw mini map
void	draw_map(t_data *data)
{
	int x_map;
	int y_map;
	int x_screen;
	int y_screen;
	int i;
	int j;
	int color;

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