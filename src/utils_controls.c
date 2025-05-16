/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:47:19 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/05/16 18:31:36 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	in_map(t_data *data, float x, float y)
{
	int	i;
	int	j;

	i = x;
	j = y;
	printf("j = %d\n", j);
	printf("height = %d\n", data->mapinfo.map_height);
	if (j >= data->mapinfo.map_height - 1 || j <= 0
		|| i >= (int)ft_strlen(data->mapinfo.map[j]) - 1 || i <= 0
		|| data->mapinfo.map[j][i] == '1')
		return (0);
	return (1);
}
