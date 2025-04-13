/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by hbutt             #+#    #+#             */
/*   Updated: 2025/04/13 15:12:28 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_texture(t_data *data)
{
	data->mapinfo.texture_north.img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.north_path, &data->mapinfo.texture_north.width,
			&data->mapinfo.texture_north.height);
	data->mapinfo.texture_south.img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.south_path, &data->mapinfo.texture_south.width,
			&data->mapinfo.texture_south.height);
	data->mapinfo.texture_east.img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.east_path, &data->mapinfo.texture_east.width,
			&data->mapinfo.texture_east.height);
	data->mapinfo.texture_west.img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.west_path, &data->mapinfo.texture_west.width,
			&data->mapinfo.texture_west.height);
	if (!data->mapinfo.texture_north.img || !data->mapinfo.texture_south.img
		|| !data->mapinfo.texture_east.img || !data->mapinfo.texture_west.img)
	{
		free_data(data);
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		exit(1);
	}
	data->mapinfo.texture_north.img_addr = mlx_get_data_addr(data->mapinfo.texture_north.img,
			&data->mapinfo.texture_north.bpp,
			&data->mapinfo.texture_north.size_line,
			&data->mapinfo.texture_north.endian);
	data->mapinfo.texture_south.img_addr = mlx_get_data_addr(data->mapinfo.texture_south.img,
			&data->mapinfo.texture_south.bpp,
			&data->mapinfo.texture_south.size_line,
			&data->mapinfo.texture_south.endian);
	data->mapinfo.texture_east.img_addr = mlx_get_data_addr(data->mapinfo.texture_east.img,
			&data->mapinfo.texture_east.bpp,
			&data->mapinfo.texture_east.size_line,
			&data->mapinfo.texture_east.endian);
	data->mapinfo.texture_west.img_addr = mlx_get_data_addr(data->mapinfo.texture_west.img,
			&data->mapinfo.texture_west.bpp,
			&data->mapinfo.texture_west.size_line,
			&data->mapinfo.texture_west.endian);
	if (!data->mapinfo.texture_north.img_addr
		|| !data->mapinfo.texture_south.img_addr
		|| !data->mapinfo.texture_east.img_addr
		|| !data->mapinfo.texture_west.img_addr)
	{
		free_data(data);
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		exit(1);
	}
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_addr = mlx_get_data_addr(data->img, &data->bpp, &data->size_line,
			&data->endian);
	if (!data->mlx || !data->win || !data->img || !data->img_addr)
	{
		free_data(data);
		ft_putstr_fd("Error\nFailed to initialize mlx\n", 2);
		exit(1);
	}
	init_texture(data);
}