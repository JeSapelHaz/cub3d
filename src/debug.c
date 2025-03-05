/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:15:47 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/05 16:09:13 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_file(t_data data)
{
	int	i;

	i = 0;
	while (data.mapinfo.file[i] != NULL)
	{
		printf("%s\n", data.mapinfo.file[i]);
		i++;
	}
}
void	print_paths(t_data data)
{
	printf("texture nord : %s\n", data.mapinfo.north_path);
	printf("texture south : %s\n", data.mapinfo.south_path);
	printf("texture west : %s\n", data.mapinfo.west_path);
	printf("texture east : %s\n", data.mapinfo.east_path);
	printf("RGB du ciel : %s\n", data.mapinfo.ceiling);
	printf("RGB du sol : %s\n", data.mapinfo.floor);
}
void	print_map(t_data data)
{
	int	i;

	i = 0;
	if (data.mapinfo.map[i] == NULL)
		printf("map vide\n");
	while (data.mapinfo.map[i] != NULL)
	{
		printf("%s\n", data.mapinfo.map[i]);
		i++;
	}
}
