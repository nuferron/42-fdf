#include "fdf.h"

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

void	initialize_wu(t_xiaolin *wu, t_point point, int num)
{
	wu->xend = ft_round(point.x);
	if (num == 1)
	{
		wu->yend = (int)point.y + wu->gradient * (wu->xend - point.x);
		wu->xgap = 1 - getting_float(point.x + 0.5);
		wu->x1 = wu->xend;
	}
	else
	{
		wu->intery = wu->yend + wu->gradient;
		wu->yend = point.y + wu->gradient * (wu->xend - point.x);
		wu->xgap = getting_float(point.x + 0.5);
		wu->x2 = wu->xend;
	}
	wu->y = (int)wu->yend;
}

void	print_extremes(t_data *data, t_xiaolin wu, int diff, int num)
{
	float	var;

	if (num == 1)
		var = wu.x1;
	else
		var = wu.x2;
	if (diff)
	{
		print_pixel(data, wu.y, var, 0xFF0000);
		print_pixel(data, wu.y + 1, var, 0x0000FF);
	}
	else
	{
		print_pixel(data, var, wu.y, 0xFF0000);
		print_pixel(data, var + 1, wu.y, 0x0000FF);
	}
}

void	print_in_between(t_data *data, t_xiaolin wu, int diff)
{
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
			print_pixel(data, wu.x1, wu.intery, 0xFF0000);
			print_pixel(data, wu.x1++, wu.intery + 1, 0x0000FF);
			wu.intery += wu.gradient;
		}
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
	initialize_wu(&wu, *origin, 1);
	print_extremes(data, wu, diff, 1);
	initialize_wu(&wu, *final, 2);
	print_extremes(data, wu, diff, 2);
	wu.x1++;
	print_in_between(data, wu, diff);
}
