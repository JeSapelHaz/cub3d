/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:19:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/16 16:09:10 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data	t_data;

typedef struct s_texture
{
	char				*path;
	void				*img;
	char				*img_addr;
	int					bpp;
	int					size_line;
	int					endian;
	int					width;
	int					height;
}						t_texture;

typedef struct s_mapinfo
{
	char				**file;
	char				**map;
	char				**copy_map;
	int					map_height;
	int					map_width;
	t_texture			textures[4];
	char				*floor;
	char				*ceiling;
	int					ceiling_color;
	int					floor_color;
}						t_mapinfo;

typedef struct s_player
{
	float				pos_x;
	float				pos_y;
	float				angle;
	float				dir_x;
	float				dir_y;
	float				slope_x;
	float				slope_y;
	float				height;
	t_data				*data;
}						t_player;

typedef struct s_keyinfo
{
	int					press_a;
	int					press_d;
	int					press_w;
	int					press_s;
	int					press_left;
	int					press_right;
}						t_keyinfo;

typedef struct s_ray
{
	float				line_height;
	float				distance;
	float				ray_angle;
	float				ray_angle_step;
	float				horz_x;
	float				horz_y;
	float				vert_x;
	float				vert_y;
	float				horz_distance;
	float				vert_distance;
	float				xo;
	float				yo;
	float				x_step;
	float				y_step;
}						t_ray;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_addr;
	int					bpp;
	int					size_line;
	int					endian;
	int					win_height;
	int					win_width;
	int					i;
	t_player			player;
	t_mapinfo			mapinfo;
	t_keyinfo			keyinfo;
	t_ray				ray;
}						t_data;

#endif