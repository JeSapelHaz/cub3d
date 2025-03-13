/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:15:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/13 18:19:33 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "colors.h"
# include "libft.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// math
# define PI 3.14159265358979323846

// keys
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESCAPE 65307

// map
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define TILE_SIZE 32
# define FOV 60
# define RAD_DEG 0.0174532925


/* CHECK ARGS */
int		check_args(int ac, char **av);

/* INIT */
void	init_data(t_data *data);

/* PARSING */
int		parse_data(char *path, t_data *data);
int		take_info_file(char **file, t_data *data);
int		check_data(t_data *data);

void	back_track(t_data *data, int start_y, int start_x, int *flag);

/* INIT MLX */
void	init_mlx(t_data *data);

/* CONTROLS */
int	actions(t_data *data);
int	key_press(int key, t_data *data);
int	key_release(int key, t_data *data);


/* DRAW */
void	clear_image(t_data *data);
void	draw_map(t_data *data);
void	put_pixel_to_image(t_data *data, float x, float y, int color);
void	draw_player(t_data *data);
void	draw_vision(t_data *data);

/* DEBUG */
void	print_file(t_data data);
void	print_paths(t_data data);
void	print_map(t_data data);
void 	print_info_player(t_data *data);

/* FREE */
void	free_data(t_data *data);

/* UTILS FUNCTIONS */
char	*ft_strndup(const char *s, size_t n);
int		ft_isspace(int c);
char	**copy_2d_map(char **map);

#endif