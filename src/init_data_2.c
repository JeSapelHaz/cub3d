/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:40:31 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/05/17 16:29:34 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// function to init parameters
void	init_parameters(t_data *data)
{
	data->ray.ray_angle = data->player.angle - (deg_to_rad(FOV) / 2.0f);
	data->ray.ray_angle_step = deg_to_rad(FOV) / (float)SCREEN_WIDTH;
	data->ray.xo = data->player.pos_x;
	data->ray.yo = data->player.pos_y;
	data->ray.x_step = 0;
	data->ray.y_step = 0;
	data->ray.horz_x = 0;
	data->ray.horz_y = 0;
	data->ray.horz_distance = 0;
	data->ray.vert_x = 0;
	data->ray.vert_y = 0;
	data->ray.vert_distance = 0;
	data->ray.distance = 0;
}
