/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:44 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 22:51:10 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// function to draw the draw raycasting
void	draw_column(t_data *data, t_draw *draw)
{
	select_texture(data, draw);
	init_draw(data, draw);
	while (++draw->y < draw->wall_end)
	{
		if (draw->y < draw->wall_start)
			put_pixel_to_image(data, draw->x, draw->y,
				data->mapinfo.ceiling_color);
		else if (draw->y >= draw->wall_start && draw->y < draw->wall_end)
		{
			draw->tex_y = (int)draw->tex_start_y & (draw->texture.height - 1);
			draw->tex_start_y += draw->step;
			put_pixel_to_image(data, draw->x, draw->y,
				*(int *)(draw->texture.img_addr + (draw->tex_y
						* draw->texture.size_line + draw->tex_start_x
						* (draw->texture.bpp >> 3))));
		}
	}
}

// function to draw the raycasting
void	draw_raycasting(t_data *data)
{
	t_ray	*ray_info;
	t_draw	draw;

	draw.x = -1;
	init_parameters(data);
	ray_info = &data->ray;
	while (++draw.x < SCREEN_WIDTH)
	{
		ray_info->horz_distance = calc_horz_distance(data);
		ray_info->vert_distance = calc_vert_distance(data);
		if (ray_info->horz_distance <= ray_info->vert_distance)
			ray_info->distance = ray_info->horz_distance
				* cosf(fix_angle(ray_info->ray_angle - data->player.angle));
		else
			ray_info->distance = ray_info->vert_distance
				* cosf(fix_angle(ray_info->ray_angle - data->player.angle));
		ray_info->ray_angle = fix_angle(ray_info->ray_angle
				+ ray_info->ray_angle_step);
		draw_column(data, &draw);
	}
}
