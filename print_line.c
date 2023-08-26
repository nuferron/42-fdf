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

void	slope_one(t_data *data, t_point origin, t_point final)
{
	float	dx;
	float	dy;

	dx = final.x - origin.x;
	dy = final.y - origin.y;
		while (origin.x != final.x && origin.y != final.y)
		{
			print_pixel(data, origin.x, origin.y, origin.color);
			origin.y += dy / fabsf(dy);
			origin.x += dx / fabsf(dx);
		}
}

/*void	slope_one_to_inf(t_data *data, t_point origin, t_point final)
{
	float	dx;
	float	dy;
	float	mod;

	mod = 1;
	while (mod > 0)
	{
		dy = final.y - origin.y;
		dx = final.x - origin.x;
		mod = sqrt(dx * dx + dy * dy);
		printf("dx: %f\tdy: %f\tmod: %f\n", dx, dy, mod);
		if (dy / mod > dx / mod)
		{
			print_pixel(data, origin.x, origin.y++, origin.color);
		}
		else
		{
			print_pixel(data, origin.x++, origin.y, origin.color);
		}
	}
}*/

void	greater_x_inc(t_data *data, t_point origin, t_point final)
{
	float	dx;
	float	dy;
	float	mod;
	float	len;

	dy = final.y - origin.y;
	dx = final.x - origin.x;
	mod = sqrt(dx * dx + dy * dy);
	printf("dx: %f\tdy: %f\tmod: %f\n", dx, dy, mod);
	//int	voltes = 0;
	len = mod;
	while (len > 0)
	{
		printf("x= %f\ty= %f\tmod= %f\tlen= %f\n", origin.x, origin.y, mod, len);
		//if ()
		//{
			print_pixel(data, origin.x, origin.y, origin.color);
		/*}
		else
		{
			print_pixel(data, origin.x++, origin.y, origin.color);
		}*/
		origin.x += dx / mod;
		origin.y += dy / mod;
		len--;
	}
}

/*void	greater_x_inc(t_data *data, t_point origin, t_point final)
{
	float	dx;
	float	dy;
	float	m;
	float	m2;

	dy = final.y - origin.y;
	dx = final.x - origin.x;
	m = dy / dx;
	m2 = 1;
	int	voltes = 0;
	while (m2 > 0 && voltes < 30)
	{
		dy = final.y - origin.y;
		dx = final.x - origin.x;
		m2 = dy / dx;
		printf("dx: %f\tdy: %f\tm: %f\n", dx, dy, m);
		if (fabsf(m2) / fabsf(m) > 1)
		{
			origin.y += dy / fabsf(dy);
			print_pixel(data, origin.x, origin.y, origin.color);
		}
		else
		{	origin.x += dx / fabsf(dx);
			print_pixel(data, origin.x, origin.y, origin.color);
		}
		voltes++;
	}
}*/

void	print_line(t_data *data, t_point origin, t_point final)
{
	float	dx;
	float	dy;
	float	m;
	//float	acc;

	dx = final.x - origin.x;
	dy = final.y - origin.y;
	m = dy / dx;
	if (dx == 0 || dy == 0)
		straight_line(data, origin, final);
	else if (m == 1 || m == -1)
		slope_one(data, origin, final);
	else if (m < 1 && m > -1)
	{
		greater_x_inc(data, origin, final);
		/*printf("m x\n");
		acc = m;
		printf("acc = %f\n", acc);
		while (origin.x != final.x && origin.y != final.y)
		{
			//printf("origin x %f\ty %f\nfinal x %f\ty %f\n\n", origin.x, origin.y, final.x, final.y);
			if (fabsf(acc) >= 1)
			{
				origin.x += (int)acc;
				acc -= (int)acc;
				print_pixel(data, origin.x, origin.y, origin.color);
				printf("acc = %f\tx = %f\n", acc, origin.x);
			}
			else
			{
				origin.y += acc / fabsf(acc);
				print_pixel(data, origin.x, origin.y, origin.color);
				printf("acc = %f\ty = %f\n", acc, origin.y);
			}
			acc += m;
			//printf("else op: acc %f\t|acc| %f\tacc/|acc| %f\n", acc, fabsf(acc), acc / fabsf(acc));
			printf("acc = %f\n", acc);
		}
	}
	else // (m > 1 && m < -1)
	{
		printf("m y\n");
		acc = 1 / m;
		while (origin.y != final.y)
		{
			printf("origin x %f\ty %f\nfinal x %f\ty %f\n", origin.x, origin.y, final.x, final.y);
			if (fabsf(acc) >= 1)
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
			acc += 1 / m;
		}*/
	}
	printf("m = %f\n", m);
}
