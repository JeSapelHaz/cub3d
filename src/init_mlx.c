/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:33 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 16:02:21 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_texture(t_data *data, int id)
{
	t_texture	*tex;

	tex = &data->mapinfo.textures[id];
	tex->img = mlx_xpm_file_to_image(data->mlx, tex->path,
			&tex->width, &tex->height);
}

static void	load_all_textures(t_data *data)
{
	load_texture(data, NORTH);
	load_texture(data, SOUTH);
	load_texture(data, EAST);
	load_texture(data, WEST);
}

static void	check_textures_loaded(t_data *data)
{
	if (!data->mapinfo.textures[NORTH].img
		|| !data->mapinfo.textures[SOUTH].img
		|| !data->mapinfo.textures[EAST].img
		|| !data->mapinfo.textures[WEST].img)
	{
		free_data(data);
		ft_putstr_fd("Error : Failed to load textures\n", 2);
		exit(1);
	}
}

static void	init_texture(t_data *data)
{
	load_all_textures(data);
	check_textures_loaded(data);
	get_texture_data(&data->mapinfo.textures[NORTH]);
	get_texture_data(&data->mapinfo.textures[SOUTH]);
	get_texture_data(&data->mapinfo.textures[EAST]);
	get_texture_data(&data->mapinfo.textures[WEST]);
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
	data->win = mlx_new_window(data->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_addr = mlx_get_data_addr(data->img,
			&data->bpp, &data->size_line, &data->endian);
	if (!data->mlx || !data->win || !data->img || !data->img_addr)
	{
		free_data(data);
		ft_putstr_fd("Error\nFailed to initialize mlx\n", 2);
		exit(1);
	}
	init_texture(data);
}
