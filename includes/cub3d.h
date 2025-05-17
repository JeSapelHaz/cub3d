/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:15:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/18 01:35:27 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "colors.h"
# include "libft.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

// screen
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

// texture path
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

// keys
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESCAPE 65307

// map
# define TILE_SIZE 32.0f
# define X_GAP 50
# define Y_GAP 50

// player
# define SPEED 0.20
# define ROTATE_SPEED 0.1
# define FOV 60

// math
# define PI 3.14159265358979323846
# define RAD_DEG 0.0174532925

/* CHECK ARGS */
int		check_args(int ac, char **av);

/* INIT DATA */
void	init_data(t_data *data);
void	init_parameters(t_data *data);

/* INIT MLX */
void	init_mlx(t_data *data);

/* DEBUG */
void	print_file(t_data data);
void	print_paths(t_data data);
void	print_map(t_data data);
void	print_info_player(t_data *data);

/* FREE */
void	free_data(t_data *data);
void	free_file_and_map(t_mapinfo *mapinfo);

/* UTILS FUNCTIONS */
char	*ft_strndup(const char *s, size_t n);
int		ft_isspace(int c);
char	**copy_2d_map(char **map);
int		convert_color(char *str);
float	distance(float x, float y);
int		count_trailing_spaces(const char *str);
int		clean_exit(t_data *data);
void	get_texture_data(t_texture *tex);

/* PARSING */
int		parse_data(char *path, t_data *data);
int		take_info_file(char **file, t_data *data);
int		check_data(t_data *data);

int		check_map(t_data *data);
void	back_track(t_data *data, int start_y, int start_x, int *flag);

/* CONTROLS */
int		actions(t_data *data);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);

/* DRAW RAYCASTING*/
void	draw_raycasting(t_data *data);

/* DRAW TEXTURES */
void	select_texture(t_data *data, t_draw *draw);
void	init_draw(t_data *data, t_draw *draw);

/* DRAW MAP*/
void	draw_2d(t_data *data);

/* DRAW */
void	clear_image(char *img_addr, int size_line, int bpp, int color);
void	put_pixel_to_image(t_data *data, int pixel_x, int pixel_y, int color);

/* UTILS MATH */
float	fix_angle(float angle);
float	deg_to_rad(float angle);

/* UTILS RAYCASTING*/
float	calc_horz_distance(t_data *data);
float	calc_vert_distance(t_data *data);
void	set_horz_variables(t_ray *ray_info);
void	set_vert_variables(t_ray *ray_info);

/* UTILS DRAW */
void	put_pixel_to_image(t_data *data, int pixel_x, int pixel_y, int color);
void	clear_image(char *img_addr, int size_line, int bpp, int color);
void	load_image(t_data *data);

/* UTILS CONTROLS */
int		in_map(t_data *data, float x, float y);
int		is_pressed(t_data *data);

#endif