#include "fdf.h"

float	ft_abs(float num)
{
	if (num < 0)
		num = -num;
	return (num);
}

void	swap_coord(t_point *origin, t_point *final)
{
	t_point	tmp;

	if (ft_abs(final.y - origin.y) > ft_abs(final.x - origin.x))
	{
		tmp = origin;
		origin = final;
		final = tmp;
	}
	else if (ft_abs(origin.x) > ft_abs(final.x))
	{
		tmp = origin;
		origin.x = origin.y;
		origin.y = tmp.x;
		tmp = final;
		final.x = final.y;
		final.y = tmp.x;
	}
}

float	getting_float(float	num)
{
	return (num - (int)num);
}

void	plot(float x, float y, int color, float bright)
{
	
}

void	print_line(t_data data, t_point origin, t_point final)
{
	float	dx;
	float	dy;
	float	gradient;
	int		xend;
	float	xgap;


	swap_coord(&origin, &final);
	dx = final.x - origin.x;
	dy = final.y - origin.y;
	if (dx == 0)
		gradient = 1;
	else
		gradient = dy / dx;
	xend = (int)origin.x;
	yend = (int)origin.y + gradient * (xend - origin.x);
	xgap = 1 - getting_float(origin.x + 0.5);
	int	x_pixel1 = xend;
	int y_pixel1 = (int)yend;
	if (ft_abs(final.y - origin.y) > ft_abs(final.x - origin.x))
	{
		plot(y_pixel1, x_pixel1, (1 - getting_float(yend)) * xgap);
		plot(y_pixel1 + 1, x_pixel1, getting_float(yend) * xgap);
	}
	else
	{
		plot(x_pixel1, y_pixel1, (1 - getting_float(yend)) * xgap);
		plot(x_pixel1, y_pixel1 + 1, getting_float(yend) * xgap);
	}
	float	intery = yend + gradient;
	xend = (int)final.x + 0.5;
	yend = final.y + gradient * (xend - final.x);
	xgap = getting_float(final.x + 0.5);
	int	x_pixel2 = xend;
	int	y_pixel2 = (int)yend;
	// Aquest if i l'anterior son el mateix, quedaria millor en una funcio a part
	if (ft_abs(final.y - origin.y) > ft_abs(final.x - origin.x))
	{
		plot(y_pixel2, x_pixel2, (1 - getting_float(yend)) * xgap);
		plot(y_pixel2 + 1, x_pixel2, getting_float(yend) * xgap);
	}
	else
	{
		plot(x_pixel2, y_pixel2, (1 - getting_float(yend)) * xgap);
		plot(x_pixel2, y_pixel2 + 1, getting_float(yend) * xgap);
	}
	x_pixel1++;
	if (ft_abs(final.y - origin.y) > ft_abs(final.x - origin.x))
	{
		while (x_pixel1 < x_pixel2)
		{
			plot((int)intery, x_pixel1, 1 - getting_float(intery));
			plot((int)intery + 1, x_pixel1, getting_float(intery));
			intery += gradient;
		}
	}
	else
	{
		while (x_pixel1 < x_pixel2)
		{
			plot(x_pixel1, (int)intery, 1 - getting_float(intery));
			plot(x_pixel1, (int)intery + 1, getting_float(intery));
			inter += gradient;
		}
	}
}
