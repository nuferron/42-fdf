#include "fdf.h"

float	ft_abs(float num)
{
	if (num < 0)
		num = -num;
	return (num);
}

float	getting_float(float num)
{
	return (num - (int)num);
}

int	ft_round(float num)
{
	if (getting_float(num) >= 0.5)
		return ((int)num + 0.5);
	return ((int)num);
}
