/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:36:57 by hdelbecq          #+#    #+#             */
/*   Updated: 2025/05/24 23:06:19 by hdelbecq         ###   ########.fr       */
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
