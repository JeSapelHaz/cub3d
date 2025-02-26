/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:15:47 by hbutt             #+#    #+#             */
/*   Updated: 2025/02/26 15:18:59 by hbutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include <stdio.h>

void print_file(t_data data)
{
    int i = 0;

    while (data.mapinfo.file[i] != NULL)
    {
        printf("%s\n", data.mapinfo.file[i]);
        i++;
    }
}
