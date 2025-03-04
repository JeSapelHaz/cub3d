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

static int get_limit(char **file)
{
    int i;
    
    while(file[i])
    {
        
    }
}

void take_info_file(t_data *data)
{
    int i;
    int limit_no_to_exceed;
    
    limit_no_to_exceed = get_limit(data->mapinfo.file);
    while(data->mapinfo.file[i] && i < limit_no_to_exceed)
}