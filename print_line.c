#include "fdf.h"

void	ft_swap(t_point *origin, t_point *final)
{
	t_point tmp;

	if (origin->x > final->x /*|| origin->y > final->y*/)
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

void	print_line(t_data *data, t_point origin, t_point final)
{
	float	dy;
	float	dx;
	float	m;
	float	acc;

	//printf("origin x %f\ty %f\nfinal x %f\ty %f\no.color %d\nf.color %d\n", origin.x, origin.y, final.x, final.y, origin.color, final.color);
	ft_swap(&origin, &final);
	//printf("origin x %f\ty %f\nfinal x %f\ty %f\no.color %d\nf.color %d\n", origin.x, origin.y, final.x, final.y, origin.color, final.color);
	dy = final.y - origin.y;
	dx = final.x - origin.x;
	m = dy / dx;
	printf("m = %f\n", m);
	if (dx == 0)
	{
		printf("dx = 0\n");
		while (origin.y <= final.y)
			print_pixel(data, origin.x, origin.y++, origin.color);
	}
	else if (dy == 0)
	{
		printf("dy = 0\n");
		while (origin.x <= final.x)
			print_pixel(data, origin.x++, origin.y, origin.color);
	}
	else if (m == 1 || m == -1)
	{
		printf("m = +-1\n");
		while (origin.x <= final.x && origin.y <= final.y)
		{
			//printf("origin x %f\ty %f\n", origin.x, origin.y);
			print_pixel(data, (origin.x)++, origin.y, origin.color);
			origin.y += m;
		}
	}
	else if (m < 1 && m > -1)
	{
		printf("m < +- 1\n");
		acc = m;
		//printf("origin x %f\ty %f\nfinal x %f\ty %f\no.color %d\nf.color %d\n", origin.x, origin.y, final.x, final.y, origin.color, final.color);
		while (origin.x <= final.x /*&& origin.y <= final.y*/)
		{
			printf("acc = %f\n", acc);
			if (fabsf(acc) >= 1)
			{
				origin.y = origin.y + (int)acc;
				printf("origin y: %f\n", origin.y);
				acc = acc - (int)acc;
				print_pixel(data, origin.x++, origin.y, origin.color);
			}
			else
			{
				print_pixel(data, origin.x++, origin.y, origin.color);
			}
			acc += m;
		}
	}
	else if (m > 1 || m < -1)
	{
		printf("m > +- 1\n");
		acc = 1 / m;
		//printf("origin x %f\ty %f\nfinal x %f\ty %f\no.color %d\nf.color %d\n", origin.x, origin.y, final.x, final.y, origin.color, final.color);
		while (origin.x <= final.x /*&& origin.y <= final.y*/)
		{
			printf("acc = %f\n", acc);
			if (fabsf(acc) > 1)
			{
				//printf("%f ", origin.y);
				origin.y = origin.y + (int)acc;
				//printf("+ %d = %f", origin.y);
				//printf("pre acc = %f\n", acc);
				acc = acc - (int)acc;
				//printf("post acc = %f\n", acc);
				print_pixel(data, origin.x++, origin.y, origin.color);
			}
			else
			{
				origin.y = origin.y + (int)acc;
				print_pixel(data, origin.x, origin.y, origin.color);
			}
			acc += 1 / m;
		}
	}
	/*else if (m > 1 || m < -1)
	{
		printf("m > +- 1\n");	
		acc = 1 / m;
		while (origin.x <= final.x && origin.y <= final.y)
		{
			printf("acc = %f\n", acc);
			if (acc < 1)
			{
				print_pixel(data, origin.x, origin.y++, origin.color);
			}
			else
			{
				acc--;
				print_pixel(data, origin.x++, origin.y++, origin.color);
			}
			acc += 1 / m;
		}
	}*/
	printf("end\n");
}
