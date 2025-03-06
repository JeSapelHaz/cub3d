/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:51 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/06 14:24:29 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_paths(t_data data)
{
	int	fd;

	(void)data;
	fd = open(data.mapinfo.north_path, O_RDONLY);
	if (fd == -1)
	{
		perror("prob path north");
		return (1);
	}
	close(fd);
	fd = open(data.mapinfo.south_path, O_RDONLY);
	if (fd == -1)
	{
		perror("prob path south");
		return (1);
	}
	close(fd);
	fd = open(data.mapinfo.west_path, O_RDONLY);
	if (fd == -1)
	{
		perror("prob path west");
		return (1);
	}
	close(fd);
	fd = open(data.mapinfo.east_path, O_RDONLY);
	if (fd == -1)
	{
		perror("prob path east");
		return (1);
	}
	close(fd);
	return (0);
}

static int	check_map(char **map)
{
	int	i;
	int	j;
	int	nbr_players;

	i = 0;
	nbr_players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S')
			{
				j++;
				nbr_players++;
				continue ;
			}
			if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != '\t' && map[i][j] != '\n' && map[i][j] != '\r'
				&& map[i][j] != '\v' && map[i][j] != '\f')
			{
				printf(" Caractere <%c> is not allowed in the map\n",
					map[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (nbr_players == 0 || nbr_players > 1)
	{
		printf("Its a game for 1 player");
		return (1);
	}
	return (0);
}
void	back_track(char **map, int y, int x, int *flag, t_data *data)
{
	data->mapinfo.map_height = 14;
	if (*flag == 0 && (map[y][x] == ' ' || (y == 0 && map[y][x] != '1')
			|| (y == data->mapinfo.map_height - 1 && map[y][x] != '1')
			|| (x == 0 && map[y][x] != '1') || (x == (int)ft_strlen(map[y] - 2)
				&& map[y][x] != '1')))
		*flag = 1;
	map[y][x] = '2';
	if (y < data->mapinfo.map_height - 1 && map[y + 1][x] != '1' && map[y
		+ 1][x] != '2')
		back_track(map, y + 1, x, flag, data);
	if (y > 0 && map[y - 1][x] != '1' && map[y - 1][x] != '2')
		back_track(map, y - 1, x, flag, data);
	if (map[y][x + 1] != '\n' && map[y][x + 1] != '\0' && map[y][x + 1] != '1'
		&& map[y][x + 1] != '2')
		back_track(map, y, x + 1, flag, data);
	if (x > 0 && map[y][x - 1] != '1' && map[y][x - 1] != '2')
		back_track(map, y, x - 1, flag, data);
}
int	check_data(t_data data)
{
	int	flag;

	flag = 0;
	if (check_paths(data) == 1)
		return (1);
	if (check_map(data.mapinfo.map) == 1)
		return (1);
	back_track(data.mapinfo.map, 11, 26, &flag, &data);
	if (flag == 1)
	{
		printf("ERRORORRR\n");
		return (1);
	}
	return (0);
}
