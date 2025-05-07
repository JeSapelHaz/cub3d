#include "../includes/cub3d.h"

float	fix_angle(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	else if (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}