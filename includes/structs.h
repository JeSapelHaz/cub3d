/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:19:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/21 16:02:35 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
typedef struct s_data	t_data;

typedef struct s_mapinfo
{
	int					map_height;
	int					map_width;
	char				*north_path;
	char				*south_path;
	char				*east_path;
	char				*west_path;
	char				*floor;
	char				*ceiling;
	char				**file;
	char				**map;
	char				**copy_map;
}						t_mapinfo;

typedef struct s_player
{
	float				pos_x;
	float				pos_y;
	float				angle;
	float				dir_x;
	float				dir_y;
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