/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:50:51 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/05 16:11:24 by hbutt            ###   ########.fr       */
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
		printf("prob north\n");
		return (1);
	}
	close(fd);
	fd = open(data.mapinfo.south_path, O_RDONLY);
	if (fd == -1)
	{
		printf("prob south\n");
		return (1);
	}
	close(fd);
	fd = open(data.mapinfo.west_path, O_RDONLY);
	if (fd == -1)
	{
		printf("prob west\n");
		return (1);
	}
	close(fd);
	fd = open(data.mapinfo.east_path, O_RDONLY);
	if (fd == -1)
	{
		printf("prob east\n");
		return (1);
	}
	close(fd);
	return (0);
}
int	check_data(t_data data)
{
	if (check_paths(data) == 1)
		return (1);
	// if (check_map(data) == 1)
	// 	return (1);
	return (0);
}