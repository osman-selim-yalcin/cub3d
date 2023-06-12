#include "cub3d.h"

int	rad_to_deg(double rad)
{
	if ((int)((rad * 180 / M_PI) * 10) % 10 < 5)
		return ((int)(rad * 180 / M_PI));
	else
		return ((int)((rad * 180 / M_PI) + 1));
}

double deg_to_rad(double degree)
{
	if (degree < 0)
		degree += 360;
	return (degree * M_PI / 180);
}

int	round_double(double num)
{
	if ((int)(num * 10) % 10 < 5)
		return ((int)num);
	else
		return ((int)(num + 1));
}

double take_approximate(double a, double b)
{
	return (a - b > -0.00001f && a - b < 0.00001f);
}