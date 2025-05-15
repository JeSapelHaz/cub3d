/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:09:22 by hbutt             #+#    #+#             */
/*   Updated: 2025/05/15 12:09:29 by hbutt            ###   ########.fr       */
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
