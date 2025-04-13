/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student->s19->be>               +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:51 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/12 16:07:07 by hbutt            ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// set the start player direction
static void	set_player_dir(t_data *data, char direction)
{
	if (direction == 'N')
		data->player.angle = N;
	else if (direction == 'E')
		data->player.angle = E;
	else if (direction == 'S')
		data->player.angle = S;
	else if (direction == 'W')
		data->player.angle = W;
}

/* Check if the paths are good*/
static int	check_paths(t_data *data)
{
	int	fd;

	fd = open(data->mapinfo.north_path, O_RDONLY);
	if (fd == -1)
		return (perror("prob path north"), 1);
	fd = open(data->mapinfo.south_path, O_RDONLY);
	if (fd == -1)
		return (perror("prob path south"), 1);
	fd = open(data->mapinfo.west_path, O_RDONLY);
	if (fd == -1)
		return (perror("prob path west"), 1);
	fd = open(data->mapinfo.east_path, O_RDONLY);
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
				data->player.pos_x = (double)j;
				data->player.pos_y = (double)i;
				set_player_dir(data, c);
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

static int	check_rgb(t_data *data)
{
	int	i;
	int	nbr_commas;

	i = 0;
	nbr_commas = 0;
	while (data->mapinfo.ceiling[i])
	{
		if (data->mapinfo.ceiling[i] == ',' && ++nbr_commas)
			i++;
		if (data->mapinfo.ceiling[i] < '0' || data->mapinfo.ceiling[i] > '9')
			return (printf("ERROR RGB syntax is RRR,GGG,BBB\n"), 1);
		i++;
	}
	i = 0;
	while (data->mapinfo.floor[i])
	{
		if (data->mapinfo.floor[i] == ',' && ++nbr_commas)
			i++;
		if (data->mapinfo.floor[i] < '0' || data->mapinfo.floor[i] > '9')
			return (printf("ERROR RGB syntax is RRR,GGG,BBB\n"), 1);
		i++;
	}
	if (nbr_commas != 4)
		return (printf("ERROR RGB syntax is RRR,GGG,BBB\n"), 1);
	return (0);
}

/* Check if the data is good */
int	check_data(t_data *data)
{
	int	flag;

	flag = 0;
	if (check_paths(data) == 1)
		return (1);
	if (check_rgb(data) == 0
		&& (data->mapinfo.ceiling_color = convert_color(data->mapinfo.ceiling)) !=
		-1
		&& (data->mapinfo.floor_color = convert_color(data->mapinfo.floor)) !=
		-1)
		;
	else
	{
		printf("ceiling color: %d\n", data->mapinfo.ceiling_color);
		printf("floor color: %d\n", data->mapinfo.floor_color);
		return (1);
	}
	if (check_map(data) == 1)
		return (1);
	data->mapinfo.copy_map = copy_2d_map(data->mapinfo.map);
	back_track(data, data->player.pos_y, data->player.pos_x, &flag);
	if (flag == 1)
		return (printf("ERRORORRR backtraking\n"), 1);
	return (0);
}
