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
	if (origin->x > final->x)
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
		wu->colo = point.color;
	}
	else
	{
		wu->intery = wu->yend + wu->gradient;
		wu->yend = point.y + wu->gradient * (wu->xend - point.x);
		wu->xgap = getting_float(point.x + 0.5);
		wu->x2 = wu->xend;
		wu->colf = point.color;
	}
	wu->y = (int)wu->yend;
}

void	print_extremes(t_structs *all, t_xiaolin *wu, int diff, int num)
{
	float	var;

	if (num == 1)
		var = wu->x1;
	else
		var = wu->x2;
	if (diff)
	{
		print_pixel(all->data, wu->y, var, wu->colo);
		print_pixel(all->data, wu->y + 1, var, wu->colo);
	}
	else
	{	
		print_pixel(all->data, var, wu->y, wu->colo);
		print_pixel(all->data, var + 1, wu->y, wu->colo);
	}
}

void	print_in_between(t_structs *all, t_xiaolin wu, int diff)
{
	if (diff)
	{
		while (wu.x1 < wu.x2)
		{
			print_pixel(all->data, wu.intery, wu.x1, wu.colo);
			print_pixel(all->data, wu.intery + 1, wu.x1++, wu.colo);
			wu.intery += wu.gradient;
		}
	}
	else
	{
		while (wu.x1 < wu.x2)
		{
			print_pixel(all->data, wu.x1, wu.intery, wu.colo);
			print_pixel(all->data, wu.x1++, wu.intery + 1, wu.colo);
			wu.intery += wu.gradient;
		}
	}
}

void	xiaolin_ft(t_structs *all, t_point origin, t_point final, t_xiaolin wu)
{
	initialize_wu(&wu, origin, 1);
	print_extremes(all, &wu, wu.diff, 1);
	initialize_wu(&wu, final, 2);
	print_extremes(all, &wu, wu.diff, 2);
	wu.x1++;
	print_in_between(all, wu, wu.diff);
}

void	put_on_place(t_point *origin, t_point *final, t_structs *all)
{
	rotation_x(all, origin, final);
	rotation_y(all, origin, final);
	rotation_z(all, origin, final);
	origin->x = origin->x * all->design->zoom + all->design->pox;
	origin->y = origin->y * all->design->zoom + all->design->poy;
	final->x = final->x * all->design->zoom + all->design->pox;
	final->y = final->y * all->design->zoom + all->design->poy;
}

void	print_line(t_structs *all, t_point origin, t_point final)
{
	float		dx;
	float		dy;
	t_xiaolin	wu;

	put_on_place(&origin, &final, all);
	wu.diff = ft_abs(final.y - origin.y) > ft_abs(final.x - origin.x);
	swap_coord(&origin, &final, wu.diff);
	dx = final.x - origin.x;
	dy = final.y - origin.y;
	if (dx == 0)
		wu.gradient = 1;
	else
		wu.gradient = dy / dx;
	xiaolin_ft(all, origin, final, wu);
}
