/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:02:44 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 14:56:01 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// function to replace a pixel color
void	put_pixel_to_image(t_data *data, int pixel_x, int pixel_y, int color)
{
	char	*pixel;

	if (pixel_x >= 0 && pixel_x < SCREEN_WIDTH && pixel_y >= 0
		&& pixel_y < SCREEN_HEIGHT)
	{
		pixel = data->img_addr + (pixel_y * data->size_line) + (pixel_x
				* (data->bpp >> 3));
		*(int *)pixel = color;
	}
}

// function to replace all pixel by black
void	clear_image(char *img_addr, int size_line, int bpp, int color)
{
	int	pixel;
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			pixel = (y * size_line) + (x * (bpp >> 3));
			*(int *)(img_addr + pixel) = color;
		}
	}
}

// function to init parameters

void	init_parameters(t_data *data)
{
	data->ray.ray_angle = data->player.angle - (degToRad(FOV) / 2.0f);
	data->ray.ray_angle_step = degToRad(FOV) / (float)SCREEN_WIDTH;
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

// function to draw the draw raycasting

void	draw_column(t_data *data, int x)
{
	int			y;
	float		wall_height;
	int			wall_start;
	int			wall_end;
	int			tex_x;
	int			tex_y;
	float		tex_pos;
	float		step;
	t_texture	*texture;

	if (data->ray.horz_distance <= data->ray.vert_distance)
	{
		if (sinf(data->ray.ray_angle) > 0)
			texture = &data->mapinfo.textures[NORTH];
		else
			texture = &data->mapinfo.textures[SOUTH];
		tex_x = (int)(data->ray.horz_x * texture->width) % texture->width;
	}
	else
	{
		if (cosf(data->ray.ray_angle) > 0)
			texture = &data->mapinfo.textures[EAST];
		else
			texture = &data->mapinfo.textures[WEST];
		tex_x = (int)(data->ray.vert_y * texture->width) % texture->width;
	}
	wall_height = ((float)SCREEN_HEIGHT / data->ray.distance);
	wall_start = roundf(((float)SCREEN_HEIGHT / 2.0f) - (wall_height / 2.0f));
	wall_end = roundf(((float)SCREEN_HEIGHT / 2.0f) + (wall_height / 2.0f));
	if (wall_start < 0)
	wall_start = 0;
	if (wall_end > SCREEN_HEIGHT)
	wall_end = SCREEN_HEIGHT;
	y = -1;
	//
	step = 1.0 * texture->height / wall_height;
	tex_pos = (wall_start - SCREEN_HEIGHT / 2 + wall_height / 2) * step;
	//
	while (++y < SCREEN_HEIGHT)
	{
		if (y < wall_start)
			put_pixel_to_image(data, x, y, data->mapinfo.ceiling_color);
		else if (y >= wall_start && y < wall_end)
		{
			tex_y = (int)tex_pos & (texture->height - 1);
			tex_pos += step;
			put_pixel_to_image(data, x, y, *(int *)(texture->img_addr + (tex_y
						* texture->size_line + tex_x * (texture->bpp >> 3))));
		}
		else
			put_pixel_to_image(data, x, y, data->mapinfo.floor_color);
	}
}

void	set_horz_variables(t_ray *ray_info)
{
	float	cotan;
	float	tan;
	float	sin;

	tan = tanf(ray_info->ray_angle);
	if (tan > -0.0001f && tan < 0.0001f)
		tan = tanf(ray_info->ray_angle + 0.0001f);
	cotan = 1.0 / tan;
	sin = sinf(ray_info->ray_angle);
	if (sin > -0.0001f && sin < 0.0001f)
		sin = sinf(ray_info->ray_angle + 0.0001f);
	if (sin >= 0.0001f) // haut
	{
		ray_info->horz_y = floorf(ray_info->yo) - 0.0001f;
		ray_info->horz_x = (ray_info->yo - ray_info->horz_y) * cotan
			+ ray_info->xo;
		ray_info->y_step = -1.0;
		ray_info->x_step = 1.0 * cotan;
	}
	else if (sin < -0.0001f) // bas
	{
		ray_info->horz_y = ceilf(ray_info->yo);
		ray_info->horz_x = (ray_info->yo - ray_info->horz_y) * cotan
			+ ray_info->xo;
		ray_info->y_step = 1.0;
		ray_info->x_step = -1.0 * cotan;
	}
}

void	set_vert_variables(t_ray *ray_info)
{
	float	tan;
	float	cos;

	tan = tanf(ray_info->ray_angle);
	cos = cosf(ray_info->ray_angle);
	if (cos > -0.0001f && cos < 0.0001f)
		cos = cosf(ray_info->ray_angle + 0.0001f);
	if (cos >= 0.0001f) // droite
	{
		ray_info->vert_x = ceilf(ray_info->xo);
		ray_info->vert_y = (ray_info->xo - ray_info->vert_x) * tan
			+ ray_info->yo;
		ray_info->x_step = 1.0;
		ray_info->y_step = -1.0 * tan;
	}
	else if (cos < -0.0001f) // gauche
	{
		ray_info->vert_x = floorf(ray_info->xo) - 0.0001f;
		ray_info->vert_y = (ray_info->xo - ray_info->vert_x) * tan
			+ ray_info->yo;
		ray_info->x_step = -1.0;
		ray_info->y_step = 1.0 * tan;
	}
}

float	calc_horz_distance(t_data *data)
{
	t_ray	*ray_info;

	ray_info = &data->ray;
	set_horz_variables(ray_info);
	while (((int)ray_info->horz_y < data->mapinfo.map_height)
		&& ((int)ray_info->horz_y >= 0
			&& ((int)ray_info->horz_x) < (int)ft_strlen(data->mapinfo.map[(int)ray_info->horz_y]))
		&& ((int)ray_info->horz_x >= 0
			&& (data->mapinfo.map[(int)ray_info->horz_y][(int)ray_info->horz_x] != '1')))
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
			&& ((int)ray_info->vert_x) < (int)ft_strlen(data->mapinfo.map[(int)ray_info->vert_y]))
		&& ((int)ray_info->vert_x > 0
			&& (data->mapinfo.map[(int)ray_info->vert_y][(int)ray_info->vert_x] != '1')))
	{
		ray_info->vert_x += ray_info->x_step;
		ray_info->vert_y += ray_info->y_step;
	}
	return (distance(ray_info->xo - ray_info->vert_x, ray_info->yo
			- ray_info->vert_y));
}

// function to draw the raycasting
void	draw_raycasting(t_data *data)
{
	t_ray	*ray_info;
	int		x;

	x = -1;
	init_parameters(data);
	ray_info = &data->ray;
	while (++x < SCREEN_WIDTH)
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
		draw_column(data, x);
	}
}
