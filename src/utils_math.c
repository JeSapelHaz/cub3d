#include "../includes/cub3d.h"

float	fix_angle(float angle)
{
	if (angle < 0.0f)
		angle += 2.0f * PI;
	else if (angle >= 2.0f * PI)
		angle -= 2.0f * PI;
	return (angle);
}