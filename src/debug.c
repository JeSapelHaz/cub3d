/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:15:47 by hbutt             #+#    #+#             */
/*   Updated: 2025/03/05 13:32:34 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

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
	printf("ici c'est la path de la texture nord %s", data.mapinfo.north_path);
	printf("ici c'est la path de la texture south %s", data.mapinfo.south_path);
	printf("ici c'est la path de la texture west %s", data.mapinfo.west_path);
	printf("ici c'est la path de la texture east %s", data.mapinfo.east_path);
	printf("ici c'est le RGB du ciel %s", data.mapinfo.ceiling);
	printf("ici c'est le RGB du sol %s", data.mapinfo.floor);
}
void	print_map(t_data data)
{
	int	i;

	i = 0;
	while (data.mapinfo.map[i] != NULL)
	{
		printf("%s\n", data.mapinfo.map[i]);
		i++;
	}
}
