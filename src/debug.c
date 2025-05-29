/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:15:47 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/29 13:00:52 by hbutt            ###   ########.fr       */
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

void	print_map(t_data data)
{
	int	i;

	i = 0;
	if (data.mapinfo.map[i] == NULL)
		printf("map null\n");
	while (data.mapinfo.map[i] != NULL)
	{
		printf("%s\n", data.mapinfo.map[i]);
		i++;
	}
}

void	print_info_player(t_data *data)
{
	printf("angle <%f>\n", data->player.angle);
	printf("dir x <%f>\n", data->player.dir_x);
	printf("dir y <%f>\n", data->player.dir_y);
	printf("fov <%d>\n", FOV);
}
