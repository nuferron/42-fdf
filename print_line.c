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

float	ft_truncate(float num)
{
	float	i;

	i = 0;
	if (num > 0)
		while (i < num)
			i++;
	else if (num < 0)
		while (i > num)
			i--;
	return (i);
}

float	ft_mod(float x, float y)
{
	return (sqrt((x * x) + (y * y)));
}

void	straight_line(t_data *data, t_point origin, t_point final)
{
	float	dx;
	float	dy;
	float	m;

	ft_swap(&origin, &final);
	dx = final.x - origin.x;
	dy = final.y - origin.y;
	m = dy / dx;
	if (dx == 0)
		while (origin.y != final.y)
			print_pixel(data, origin.x, origin.y++, origin.color);
	else if (dy == 0)
		while (origin.x != final.x)
			print_pixel(data, origin.x++, origin.y, origin.color);
}

void	print_line(t_data *data, t_point origin, t_point final)
{
	float	dx;
	float	dy;
	float	m;
	float	acc;

	dx = final.x - origin.x;
	dy = final.y - origin.y;
	m = dy / dx;
	/*if (dx == 0)
		while (origin.y != final.y)
			print_pixel(data, origin.x, origin.y++, origin.color);
	else if (dy == 0)
		while (origin.x != final.x)
			print_pixel(data, origin.x++, origin.y, origin.color);*/
	if (dx == 0 || dy == 0)
		straight_line(data, origin, final);
	else if (m == 1 || m == -1)
	{
		while (origin.x != final.x && origin.y != final.y)
		{
			printf("origin x %f\ty %f\nfinal x %f\ty %f\n\n", origin.x, origin.y, final.x, final.y);
			print_pixel(data, origin.x++, origin.y, origin.color);
			origin.y += m;
		}
	}
	else if (m < 1 && m > -1)
	{
		printf("m x\n");
		acc = m;
		while (origin.x != final.x && origin.y != final.y)
		{
			//printf("origin x %f\ty %f\nfinal x %f\ty %f\n\n", origin.x, origin.y, final.x, final.y);
			if (fabsf(acc) == 1)
			{
				origin.y += (int)acc;
				acc -= (int)acc;
				print_pixel(data, origin.x, origin.y, origin.color);
				printf("acc = %f\ty = %f\n", acc, origin.y);
			}
			else
			{
				origin.x += acc / fabsf(acc);
				print_pixel(data, origin.x, origin.y, origin.color);
				printf("acc = %f\tx = %f\n", acc, origin.x);
			}
			acc += m;
			printf("else op: acc %f\t|acc| %f\tacc/|acc| %f\n", acc, fabsf(acc), acc / fabsf(acc));
			printf("acc = %f\n", acc);
		}
	}
	else // (m > 1 && m < -1)
	{
		printf("m y\n");
		acc = 1 / m;
		while (origin.y != final.y)
		{
			printf("origin x %f\ty %f\nfinal x %f\ty %f\no.color %d\nf.color %d\n", origin.x, origin.y, final.x, final.y, origin.color, final.color);
			if (fabsf(acc) >= 1)
			{
				origin.y += (int)acc;
				acc -= (int)acc;
				print_pixel(data, origin.x, origin.y, origin.color);
			}
			else
			{
				origin.y += acc / fabsf(acc);
				print_pixel(data, origin.x, origin.y, origin.color);
			}
			acc += 1 / m;
		}
	}
}
