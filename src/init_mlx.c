/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/07 13:34:39 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_data *data)
{
	int		i;
	int		j;
	int		img_height;
	void	*img_wall;

	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 2000, (data->mapinfo.map_height
				+ 1) * 64, "cub3d");
	if (!data->mlx || !data->window)
	{
		perror("Error initializing MLX");
		exit(1);
	}
	i = 0;
	img_height = 64;
	img_wall = mlx_xpm_file_to_image(data->mlx, data->mapinfo.east_path,
			&img_height, &img_height);
	if (!img_wall)
	{
		perror("Error loading wall image");
		exit(1);
	}
	while (data->mapinfo.map[i])
	{
		j = 0;
		while (data->mapinfo.map[i][j])
		{
			if (data->mapinfo.map[i][j] == '1')
			{
				mlx_put_image_to_window(data->mlx, data->window, img_wall, j
					* 64, i * 64);
			}
			j++;
		}
		i++;
	}
}
