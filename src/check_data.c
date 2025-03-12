/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student->s19->be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:51 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/12 16:07:07 by hbutt            ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
				data->player.pos_x = (float)j;
				data->player.pos_y = (float)i;
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
	char	**rgb;

	rgb = ft_split(data->mapinfo.ceiling, ',');
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
		return (printf("ERROR RGB CEILING\n"), 1);
	if (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
		return (printf("ERROR RGB CEILING\n"), 1);
	if (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0)
		return (printf("ERROR RGB CEILING\n"), 1);
	rgb = ft_split(data->mapinfo.floor, ',');
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[0]) < 0)
		return (printf("ERROR RGB FLOOR\n"), 1);
	if (ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[1]) < 0)
		return (printf("ERROR RGB FLOOR\n"), 1);
	if (ft_atoi(rgb[2]) > 255 || ft_atoi(rgb[2]) < 0)
		return (printf("ERROR RGB FLOOR\n"), 1);
	return (0);
}

/* Check if the data is good */
int	check_data(t_data *data)
{
	int	flag;

	flag = 0;
	if (check_paths(data) == 1)
		return (1);
	if (check_rgb(data) == 1)
		return (1);
	if (check_map(data) == 1)
		return (1);
	data->mapinfo.copy_map = copy_2d_map(data->mapinfo.map);
	back_track(data, data->player.pos_y, data->player.pos_x, &flag);
	if (flag == 1)
	{
		printf("ERRORORRR\n");
		return (1);
	}
	return (0);
}