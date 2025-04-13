/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:19:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/04/13 15:03:43 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
typedef struct s_data	t_data;

typedef struct s_texture
{
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
	char				*north_path;
	char				*south_path;
	char				*east_path;
	char				*west_path;
	t_texture			texture_north;
	t_texture			texture_south;
	t_texture			texture_east;
	t_texture			texture_west;
	char				*floor;
	char				*ceiling;
	int					ceiling_color;
	int					floor_color;
}						t_mapinfo;

typedef struct s_player
{
	double				pos_x;
	double				pos_y;
	double				angle;
	double				dir_x;
	double				dir_y;
	double				height;
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
}						t_data;

#endif