/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:09:22 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 17:39:34 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	fix_angle(float angle)
{
	if (angle < 0.0f)
		angle += 2.0f * PI;
	else if (angle >= 2.0f * PI)
		angle -= 2.0f * PI;
	return (angle);
}

// sin pos => up sin / neg => down
void	set_horz_variables(t_ray *ray_info)
{
	ray_info->tan = tanf(ray_info->ray_angle);
	if (ray_info->tan > -0.0001f && ray_info->tan < 0.0001f)
		ray_info->tan = tanf(ray_info->ray_angle + 0.0001f);
	ray_info->sin = sinf(ray_info->ray_angle);
	if (ray_info->sin > -0.0001f && ray_info->sin < 0.0001f)
		ray_info->sin = sinf(ray_info->ray_angle + 0.0001f);
	ray_info->cotan = 1.0 / ray_info->tan;
	if (ray_info->sin >= 0.0001f)
	{
		ray_info->horz_y = floorf(ray_info->yo) - 0.0001f;
		ray_info->horz_x = (ray_info->yo - ray_info->horz_y) * ray_info->cotan
			+ ray_info->xo;
		ray_info->y_step = -1.0;
		ray_info->x_step = ray_info->cotan;
	}
	else if (ray_info->sin < -0.0001f)
	{
		ray_info->horz_y = ceilf(ray_info->yo);
		ray_info->horz_x = (ray_info->yo - ray_info->horz_y) * ray_info->cotan
			+ ray_info->xo;
		ray_info->y_step = 1.0;
		ray_info->x_step = -ray_info->cotan;
	}
}

// cos pos => right cos / neg => left
void	set_vert_variables(t_ray *ray_info)
{
	ray_info->tan = tanf(ray_info->ray_angle);
	ray_info->cos = cosf(ray_info->ray_angle);
	if (ray_info->cos > -0.0001f && ray_info->cos < 0.0001f)
		ray_info->cos = cosf(ray_info->ray_angle + 0.0001f);
	if (ray_info->cos >= 0.0001f)
	{
		ray_info->vert_x = ceilf(ray_info->xo);
		ray_info->vert_y = (ray_info->xo - ray_info->vert_x) * ray_info->tan
			+ ray_info->yo;
		ray_info->x_step = 1.0;
		ray_info->y_step = -ray_info->tan;
	}
	else if (ray_info->cos < -0.0001f)
	{
		ray_info->vert_x = floorf(ray_info->xo) - 0.0001f;
		ray_info->vert_y = (ray_info->xo - ray_info->vert_x) * ray_info->tan
			+ ray_info->yo;
		ray_info->x_step = -1.0;
		ray_info->y_step = ray_info->tan;
	}
}

float	calc_horz_distance(t_data *data)
{
	t_ray	*ray_info;

	ray_info = &data->ray;
	set_horz_variables(ray_info);
	while (((int)ray_info->horz_y < data->mapinfo.map_height)
		&& ((int)ray_info->horz_y >= 0
			&& \
			((int)ray_info->horz_x) < (int)ft_strlen \
		(data->mapinfo.map[(int)ray_info->horz_y]))
		&& ((int)ray_info->horz_x >= 0 \
			&& (data->mapinfo.map[(int)ray_info->horz_y][(int)ray_info->horz_x] \
			!= '1')))
	{
		ray_info->horz_x += ray_info->x_step;
		ray_info->horz_y += ray_info->y_step;
	}
	return (distance(ray_info->xo - ray_info->horz_x, ray_info->yo
			- ray_info->horz_y));
}

float	calc_vert_distance(t_data *data)
{
	t_ray	*ray_info;

	ray_info = &data->ray;
	set_vert_variables(ray_info);
	while (((int)ray_info->vert_y < data->mapinfo.map_height)
		&& ((int)ray_info->vert_y > 0
			&& ((int)ray_info->vert_x) < \
			(int)ft_strlen(data->mapinfo.map[(int)ray_info->vert_y]))
		&& ((int)ray_info->vert_x > 0
			&& (data->mapinfo.map[(int)ray_info->vert_y][(int)ray_info->vert_x] \
			!= '1')))
	{
		ray_info->vert_x += ray_info->x_step;
		ray_info->vert_y += ray_info->y_step;
	}
	return (distance(ray_info->xo - ray_info->vert_x, ray_info->yo
			- ray_info->vert_y));
}
