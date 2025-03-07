/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:15:39 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/07 15:02:22 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
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
# define SPEED 10
# define ANGLE 5
# define LOG 0

// map
# define SCREEN_WIDTH 2500
# define SCREEN_HEIGHT 1500

typedef struct s_mapinfo
{
	int			map_height;
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	char		*floor;
	char		*ceiling;
	int			pos_x;
	int			pos_y;
	char		**file;
	char		**map;

}				t_mapinfo;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	void		*win_height;
	void		*win_width;
	t_mapinfo	mapinfo;
}				t_data;

/* CHECK ARGS */
int				check_args(int ac, char **av);

/* INIT */
void			init_data(t_data *data);

/* PARSING */
int				parse_data(char *path, t_data *data);
int				take_info_file(char **file, t_data *data);
int				check_data(t_data data);

void			back_track(t_data *data, int y, int x, int *flag);

/* INIT MLX */
void			init_mlx(t_data *data);

/* CONTROLS */
int	controls(int keycode, t_data *data);

/* DEBUG */
void			print_file(t_data data);
void			print_paths(t_data data);
void			print_map(t_data data);

/* FREE */
void			free_data(t_data *data);

/* UTILS FUNCTIONS */
char			*ft_strndup(const char *s, size_t n);

#endif