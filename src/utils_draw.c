/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:17:06 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/05/16 23:41:33 by hdelbecq         ###   ########.fr       */
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
void	clear_image(char *img_addr, int size_line, int bpp, int color)
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
			pixel = (y * size_line) + (x * (bpp >> 3));
			*(int *)(img_addr + pixel) = color;
		}
	}
}

// function to replace all pixel by floor color
void	load_image(t_data *data)
{
	clear_image(data->img_addr, data->size_line, \
		data->bpp, data->mapinfo.floor_color);
	draw_raycasting(data);
	draw_2d(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
