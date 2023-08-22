#include "fdf.h"

void	ft_swap(t_point *origin, t_point *final)
{
	t_point tmp;

	if (origin->x > final->x || origin->y > final->y)
	{
		tmp = *origin;
		*origin = *final;
		*final = tmp;
	}
}

void	print_line(t_data *data, t_point origin, t_point final)
{
	float	dy;
	float	dx;
	float	m;
	float	acc;

	//printf("origin x %f\ty %f\nfinal x %f\ty %f\n", origin.x, origin.y, final.x, final.y);
	ft_swap(&origin, &final);
	dy = final.y - origin.y;
	dx = final.x - origin.x;
	m = dy / dx;
	if (dx == 0)
		while (origin.y <= final.y)
			print_pixel(data, origin.x, origin.y++, origin.color);
	else if (dy == 0)
		while (origin.x <= final.x)
			print_pixel(data, origin.x++, origin.y, origin.color);
	else if (m == 1)
		while (origin.x <= final.x && origin.y <= final.y)
			print_pixel(data, origin.x++, origin.y++, origin.color);
	else if (m < 1 && m > -1)
	{
		acc = m;
		while (origin.x <= final.x && origin.y <= final.y)
		{
			if (acc < 1)
				print_pixel(data, origin.x++, origin.y, origin.color);
			else
			{
				acc--;
				print_pixel(data, origin.x++, origin.y++, origin.color);
			}
			acc += m;
		}
	}
	else if (m > 1 || m < -1)
	{
		acc = 1 / m;
		while (origin.x <= final.x && origin.y <= final.y)
		{
			if (acc < 1)
				print_pixel(data, origin.x, origin.y++, origin.color);
			else
			{
				acc--;
				print_pixel(data, origin.x++, origin.y++, origin.color);
			}
			acc += 1 / m;
		}
	}
}
