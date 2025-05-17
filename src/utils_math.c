/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:09:22 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/17 16:37:23 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	fix_angle(float angle)
{
	if (angle < 0.0f)
		angle += 2.0f * PI;
	else if (angle >= 2.0f * PI)
		angle -= 2.0f * PI;
	return (angle);
}

float	deg_to_rad(float angle)
{
	return (angle * PI / 180.0f);
}
