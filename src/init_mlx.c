/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/10 15:39:41 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_data *data)
{
	int		x;
	int		y;
	char	*pixel;

	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"cub3d");
	if (!data->mlx || !data->window)
	{
		perror("Error initializing MLX");
		exit(1);
	}
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			pixel = data->addr + (y * data->line_length + x
					* (data->bits_per_pixel / 8));
			*(unsigned int *)pixel = GRAY;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
