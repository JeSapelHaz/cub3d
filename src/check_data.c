/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:51 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/07 13:18:40 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Check if the paths are good*/
static int	check_paths(t_data data)
{
	int	fd;

	fd = open(data.mapinfo.north_path, O_RDONLY);
	if (fd == -1)
		return (perror("prob path north"), 1);
	fd = open(data.mapinfo.south_path, O_RDONLY);
	if (fd == -1)
		return (perror("prob path south"), 1);
	fd = open(data.mapinfo.west_path, O_RDONLY);
	if (fd == -1)
		return (perror("prob path west"), 1);
	fd = open(data.mapinfo.east_path, O_RDONLY);
	if (fd == -1)
		return (perror("prob path east"), 1);
	return (close(fd), 0);
}

static int	check_map_chars(t_data *data, int *nbr_players)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (data->mapinfo.map[++i])
	{
		j = -1;
		while (data->mapinfo.map[i][++j])
		{
			c = data->mapinfo.map[i][j];
			if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
			{
				data->mapinfo.pos_x = i;
				data->mapinfo.pos_y = j;
				(*nbr_players)++;
			}
			else if (c != ' ' && c != '1' && c != '0' && c != '\t' && c != '\n'
				&& c != '\r' && c != '\v' && c != '\f')
				return (printf("Caracter <%c> not allowed in the map\n", c), 1);
		}
	}
	return (0);
}

static int	check_map(t_data *data)
{
	int	nbr_players;

	nbr_players = 0;
	if (check_map_chars(data, &nbr_players))
		return (1);
	if (nbr_players == 0 || nbr_players > 1)
	{
		printf("Its a game for 1 player\n");
		return (1);
	}
	return (0);
}

/* Check is the map is valid or not */
void	back_track(t_data *data, int y, int x, int *flag)
{
	if (*flag == 0 && (data->mapinfo.map[y][x] == ' ' || (y == 0
			&& data->mapinfo.map[y][x] != '1')
			|| (y == data->mapinfo.map_height - 1
				&& data->mapinfo.map[y][x] != '1') || (x == 0
				&& data->mapinfo.map[y][x] != '1')
			|| (x == (int)ft_strlen(data->mapinfo.map[y] - 2)
				&& data->mapinfo.map[y][x] != '1')))
		*flag = 1;
	data->mapinfo.map[y][x] = '2';
	if (y < data->mapinfo.map_height - 1 && data->mapinfo.map[y + 1][x] != '1'
		&& data->mapinfo.map[y + 1][x] != '2')
		back_track(data, y + 1, x, flag);
	if (y > 0 && data->mapinfo.map[y - 1][x] != '1' && data->mapinfo.map[y
		- 1][x] != '2')
		back_track(data, y - 1, x, flag);
	if (data->mapinfo.map[y][x + 1] != '\n' && data->mapinfo.map[y][x
		+ 1] != '\0' && data->mapinfo.map[y][x + 1] != '1'
		&& data->mapinfo.map[y][x + 1] != '2')
		back_track(data, y, x + 1, flag);
	if (x > 0 && data->mapinfo.map[y][x - 1] != '1' && data->mapinfo.map[y][x
		- 1] != '2')
		back_track(data, y, x - 1, flag);
}

/* Check if the data is good */
int	check_data(t_data data)
{
	int	flag;

	flag = 0;
	if (check_paths(data) == 1)
		return (1);
	if (check_map(&data) == 1)
		return (1);
	back_track(&data, data.mapinfo.pos_x, data.mapinfo.pos_y, &flag);
	if (flag == 1)
	{
		printf("ERRORORRR\n");
		return (1);
	}
	return (0);
}
