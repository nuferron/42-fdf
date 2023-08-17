#include "fdf.h"

void	print_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_square(t_data *data, t_square *square)
{
	int	i;
	int	xo;

	i = -1;
	xo = square->x;
	while (i < square->dim)
	{
		print_pixel(data, xo, square->y, square->color);
		print_pixel(data, xo, square->y + square->dim, square->color);
		xo++;
		i++;
	}
	i = -1;
	while (i < square->dim)
	{
		print_pixel(data, square->x, square->y, square->color);
		print_pixel(data, square->x + square->dim, square->y, square->color);
		(square->y)++;
		i++;
	}
}
