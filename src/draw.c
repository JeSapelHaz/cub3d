#include "../includes/cub3d.h"

void	draw_pixel(t_data *data, int x, int y, int color)
{
	int	pixel;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel = (y * data->size_line) + (x * (data->bpp / 8));
		data->img_addr[pixel] = color & 0xFF;
		data->img_addr[pixel + 1] = (color >> 8) & 0xFF;
		data->img_addr[pixel + 2] = (color >> 16) & 0xFF;
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
			data->img_addr[pixel] = 0;     // R
			data->img_addr[pixel + 1] = 0; // G
			data->img_addr[pixel + 2] = 0; // B
		}
	}
}

void	draw_line(t_data *data, int x1, int y1, int color)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - data->player.pos_x);
	sx = data->player.pos_x < x1 ? 1 : -1;
	dy = -abs(y1 - data->player.pos_y);
	sy = data->player.pos_x < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		drawPixel(data, data->player.pos_x, data->player.pos_y, color);
		if (data->player.pos_x == x1 && data->player.pos_y == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			data->player.pos_x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			data->player.pos_y += sy;
		}
	}
}
