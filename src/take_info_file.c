/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:17:01 by hbutt             #+#    #+#             */
/*   Updated: 2025/02/26 18:00:46 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void take_info_file(char **file, t_data *data)
{
    int i;
    
    i = 0;
    while (file[i])
    {
        if (file[i][0] == 'N' && file[i][1] == 'O')
        {
            data->mapinfo.north_path = ft_strdup(&file[i][3]);
            // printf("ici c'est la path de la texture nord %s", data->mapinfo.north_path);
        }
        if (file[i][0] == 'S' && file[i][1] == 'O')
        {
            data->mapinfo.south_path = ft_strdup(&file[i][3]);
            // printf("ici c'est la path de la texture south %s", data->mapinfo.south_path);
        }
        if (file[i][0] == 'W' && file[i][1] == 'E')
        {
            data->mapinfo.west_path = ft_strdup(&file[i][3]);
            // printf("ici c'est la path de la texture west %s", data->mapinfo.west_path);
        }
        if (file[i][0] == 'E' && file[i][1] == 'A')
        {
            data->mapinfo.east_path = ft_strdup(&file[i][3]);
            // printf("ici c'est la path de la texture east %s", data->mapinfo.east_path);
        }
        if (file[i][0] == 'C')
        {
            data->mapinfo.ceiling = ft_strdup(&file[i][2]);
            // printf("ici c'est le RGB du ciel %s", data->mapinfo.ceiling);
        }
        if (file[i][0] == 'F')
        {
            data->mapinfo.floor = ft_strdup(&file[i][2]);
            // printf("ici c'est le RGB du sol %s", data->mapinfo.floor);
        }
        i++;
    } 
}