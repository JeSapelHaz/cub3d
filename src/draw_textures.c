/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:55:14 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 19:15:47 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	select_texture(t_data *data, t_draw *draw)
{
	if (data->ray.horz_distance <= data->ray.vert_distance)
	{
		if (sinf(data->ray.ray_angle) > 0.0f)
			draw->texture = data->mapinfo.textures[SOUTH];
		else
			draw->texture = data->mapinfo.textures[NORTH];
		draw->tex_start_x = (int)(data->ray.horz_x
				* draw->texture.width) & (draw->texture.width - 1);
	}
	else
	{
		if (cosf(data->ray.ray_angle) > 0.0f)
			draw->texture = data->mapinfo.textures[EAST];
		else
			draw->texture = data->mapinfo.textures[WEST];
		draw->tex_start_x = (int)(data->ray.vert_y
				* draw->texture.width) & (draw->texture.width - 1);
	}
}

void	init_draw(t_data *data, t_draw *draw)
{
	draw->wall_height = ((float)SCREEN_HEIGHT / data->ray.distance);
	draw->wall_start = roundf(((float)SCREEN_HEIGHT / 2.0f) - (draw->wall_height
				/ 2.0f));
	draw->wall_end = roundf(((float)SCREEN_HEIGHT / 2.0f) + (draw->wall_height
				/ 2.0f));
	if (draw->wall_start < 0)
		draw->wall_start = 0;
	if (draw->wall_end > SCREEN_HEIGHT)
		draw->wall_end = SCREEN_HEIGHT;
	draw->y = -1;
	draw->step = (float)draw->texture.height / (float)draw->wall_height;
	draw->tex_start_y = (draw->wall_start - SCREEN_HEIGHT / 2.0f
			+ draw->wall_height / 2.0f) * draw->step;
}
