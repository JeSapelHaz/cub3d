/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:36:57 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/05/18 03:15:50 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_pressed(t_data *data)
{
	if (data->keyinfo.press_a || data->keyinfo.press_w || data->keyinfo.press_s
		|| data->keyinfo.press_d || data->keyinfo.press_left
		|| data->keyinfo.press_right)
		return (1);
	return (0);
}

float	fix_angle(float angle)
{
	if (angle < 0.0f)
		angle += 2.0f * PI;
	else if (angle >= 2.0f * PI)
		angle -= 2.0f * PI;
	return (angle);
}

void	fix_coord(t_player *player, float *player_x, float *player_y)
{
	t_mapinfo	*mapinfo;
	int			pos_x;
	int			pos_y;

	mapinfo = &player->data->mapinfo;
	pos_y = ceilf(*player_y);
	pos_x = ceilf(*player_x);
	if (mapinfo->map[pos_y][(int)*player_x] == '1' && (float)pos_y
		- *player_y < 0.3f)
		*player_y = (float)pos_y - 0.3f;
	if (mapinfo->map[(int)*player_y][pos_x] == '1' && (float)pos_x
		- *player_x < 0.3f)
		*player_x = (float)pos_x - 0.3f;
	pos_y = floorf(*player_y) - 1;
	pos_x = floorf(*player_x) - 1;
	if (mapinfo->map[pos_y][(int)*player_x] == '1' && *player_y
		- (float)pos_y < 1.3f)
		*player_y = (float)pos_y + 1.3f;
	if (mapinfo->map[(int)*player_y][pos_x] == '1' && *player_x
		- (float)pos_x < 1.3f)
		*player_x = (float)pos_x + 1.3f;
}
