/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:51 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 20:16:21 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Check if the paths are good*/
static int	check_paths(t_data *data)
{
	int		fd;
	int		i;
	char	*names[4];

	names[0] = "Problem path north";
	names[1] = "Problem path south";
	names[2] = "Problem path east";
	names[3] = "Problem path west";
	i = 0;
	while (i < 4)
	{
		fd = open(data->mapinfo.textures[i].path, O_RDONLY);
		if (fd == -1)
		{
			perror(names[i]);
			return (1);
		}
		close(fd);
		i++;
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
