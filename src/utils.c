/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:26:49 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 16:31:23 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_file_and_map(t_mapinfo *mapinfo)
{
	int i = 0;

	if (mapinfo->file)
	{
		while (mapinfo->file[i])
			free(mapinfo->file[i++]);
		free(mapinfo->file);
		mapinfo->file = NULL;
	}
	i = 0;
	if (mapinfo->map)
	{
		while (mapinfo->map[i])
			free(mapinfo->map[i++]);
		free(mapinfo->map);
		mapinfo->map = NULL;
	}
	i = 0;
	if (mapinfo->copy_map)
	{
		while (mapinfo->copy_map[i])
			free(mapinfo->copy_map[i++]);
		free(mapinfo->copy_map);
		mapinfo->copy_map = NULL;
	}
}
static void	free_textures_paths(t_mapinfo *mapinfo)
{
	free(mapinfo->textures[NORTH].path);
	free(mapinfo->textures[SOUTH].path);
	free(mapinfo->textures[EAST].path);
	free(mapinfo->textures[WEST].path);
	free(mapinfo->ceiling);
	free(mapinfo->floor);
	mapinfo->textures[NORTH].path = NULL;
	mapinfo->textures[SOUTH].path = NULL;
	mapinfo->textures[EAST].path = NULL;
	mapinfo->textures[WEST].path = NULL;
}
static void	destroy_images(t_data *data)
{
	if (!data->mlx)
		return;
	if (data->mapinfo.textures[NORTH].img)
		mlx_destroy_image(data->mlx, data->mapinfo.textures[NORTH].img);
	if (data->mapinfo.textures[SOUTH].img)
		mlx_destroy_image(data->mlx, data->mapinfo.textures[SOUTH].img);
	if (data->mapinfo.textures[EAST].img)
		mlx_destroy_image(data->mlx, data->mapinfo.textures[EAST].img);
	if (data->mapinfo.textures[WEST].img)
		mlx_destroy_image(data->mlx, data->mapinfo.textures[WEST].img);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
}
static void	destroy_window_and_display(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return;
	destroy_images(data);
	destroy_window_and_display(data);
	free_file_and_map(&data->mapinfo);
	free_textures_paths(&data->mapinfo);
}

