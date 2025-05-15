/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 12:01:40 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_texture(t_data *data)
{
	data->mapinfo.textures[NORTH].img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.textures[NORTH].path,
			&data->mapinfo.textures[NORTH].width,
			&data->mapinfo.textures[NORTH].height);
	data->mapinfo.textures[SOUTH].img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.textures[SOUTH].path,
			&data->mapinfo.textures[SOUTH].width,
			&data->mapinfo.textures[SOUTH].height);
	data->mapinfo.textures[EAST].img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.textures[EAST].path,
			&data->mapinfo.textures[EAST].width,
			&data->mapinfo.textures[EAST].height);
	data->mapinfo.textures[WEST].img = mlx_xpm_file_to_image(data->mlx,
			data->mapinfo.textures[WEST].path,
			&data->mapinfo.textures[WEST].width,
			&data->mapinfo.textures[WEST].height);
	if (!data->mapinfo.textures[NORTH].img || !data->mapinfo.textures[SOUTH].img
		|| !data->mapinfo.textures[EAST].img
		|| !data->mapinfo.textures[WEST].img)
	{
		free_data(data);
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		exit(1);
	}
	data->mapinfo.textures[NORTH].img_addr = mlx_get_data_addr(data->mapinfo.textures[NORTH].img,
			&data->mapinfo.textures[NORTH].bpp,
			&data->mapinfo.textures[NORTH].size_line,
			&data->mapinfo.textures[NORTH].endian);
	data->mapinfo.textures[SOUTH].img_addr = mlx_get_data_addr(data->mapinfo.textures[SOUTH].img,
			&data->mapinfo.textures[SOUTH].bpp,
			&data->mapinfo.textures[SOUTH].size_line,
			&data->mapinfo.textures[SOUTH].endian);
	data->mapinfo.textures[EAST].img_addr = mlx_get_data_addr(data->mapinfo.textures[EAST].img,
			&data->mapinfo.textures[EAST].bpp,
			&data->mapinfo.textures[EAST].size_line,
			&data->mapinfo.textures[EAST].endian);
	data->mapinfo.textures[WEST].img_addr = mlx_get_data_addr(data->mapinfo.textures[WEST].img,
			&data->mapinfo.textures[WEST].bpp,
			&data->mapinfo.textures[WEST].size_line,
			&data->mapinfo.textures[WEST].endian);
	if (!data->mapinfo.textures[NORTH].img_addr
		|| !data->mapinfo.textures[SOUTH].img_addr
		|| !data->mapinfo.textures[EAST].img_addr
		|| !data->mapinfo.textures[WEST].img_addr)
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