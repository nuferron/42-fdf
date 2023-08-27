#include "fdf.h"

float	ft_abs(float num)
{
	if (num < 0)
		num = -num;
	return (num);
}

float	getting_float(float	num)
{
	return (num - (int)num);
}

int	ft_round(float num)
{
	if (getting_float(num) >= 0.5)
		return ((int)num + 0.5);
	return ((int)num);
}

void	swap_coord(t_point *origin, t_point *final, int diff)
{
	t_point	tmp;
	
	if (diff)
	{
		tmp = *origin;
		origin->x = origin->y;
		origin->y = tmp.x;
		tmp = *final;
		final->x = final->y;
		final->y = tmp.x;
	}
	if (ft_abs(origin->x) > ft_abs(final->x))
	{
		tmp = *origin;
		origin->x = final->x;
		origin->y = final->y;
		final->x = tmp.x;
		final->y = tmp.y;
	}
}

void	print_line(t_data *data, t_point *origin, t_point *final)
{
	float		dx;
	float		dy;
	int			diff;
	t_xiaolin	wu;

	diff = ft_abs(final->y - origin->y) > ft_abs(final->x - origin->x);
	swap_coord(origin, final, diff);
	dx = final->x - origin->x;
	dy = final->y - origin->y;
	if (dx == 0)
		wu.gradient = 1;
	else
		wu.gradient = dy / dx;
	/////////////////////////////////
	wu.xend = ft_round(origin->x);
	wu.yend = (int)origin->y + wu.gradient * (wu.xend - origin->x);
	wu.xgap = 1 - getting_float(origin->x + 0.5);
	wu.x1 = wu.xend;
	wu.y1 = (int)wu.yend;
	if (diff)
	{
		print_pixel(data, wu.y1, wu.x1, 0xFF0000);
		print_pixel(data, wu.y1 + 1, wu.x1, 0x0000FF);
	}
	else
	{
		print_pixel(data, wu.x1, wu.y1, 0xFF0000);
		print_pixel(data, wu.x1 + 1, wu.y1, 0x0000FF);
	}
	////////////////////////////
	wu.intery = wu.yend + wu.gradient;
	wu.xend = ft_round(final->x);
	wu.yend = final->y + wu.gradient * (wu.xend - final->x);
	wu.xgap = getting_float(final->x + 0.5);
	wu.x2 = wu.xend;
	wu.y2 = (int)wu.yend;
	if (diff)
	{
		print_pixel(data, wu.y2, wu.x2, 0xFF0000);
		print_pixel(data, wu.y2 + 1, wu.x2, 0x0000FF);
	}
	else
	{
		print_pixel(data, wu.x2, wu.y2, 0xFF0000);
		print_pixel(data, wu.x2 + 1, wu.y2, 0x0000FF);
	}

	///////////////////////////////////
	wu.x1++;
	if (diff)
	{
		while (wu.x1 < wu.x2)
		{
			print_pixel(data, wu.intery, wu.x1, 0xFF0000);
			print_pixel(data, wu.intery + 1, wu.x1++, 0x0000FF);
			wu.intery += wu.gradient;
		}
	}
	else
	{
		while (wu.x1 < wu.x2)
		{
			print_pixel(data, wu.x1,  wu.intery, 0xFF0000);
			print_pixel(data, wu.x1++, wu.intery + 1, 0x0000FF);
			wu.intery += wu.gradient;
		}
	}
}
