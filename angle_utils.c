#include "cub3d.h"

int	rad_to_deg(float rad)
{
	if ((int)((rad * 180 / M_PI) * 10) % 10 < 5)
		return ((int)(rad * 180 / M_PI));
	else
		return ((int)((rad * 180 / M_PI) + 1));
}

float deg_to_rad(float degree)
{
	return (degree * M_PI / 180);
}

int	round_float(float num)
{
	if ((int)(num * 10) % 10 < 5)
		return ((int)num);
	else
		return ((int)(num + 1));
}