#include "fdf.h"

unsigned int trgb_to_hex(int t, int r, int g, int b) {
    return ((t & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

/*void print_pixel(t_data *data, t_point pixel) {

    char *dst = data->addr + ((int)pixel.y * data->line_len + (int)pixel.x * (data->bpp / 8));
    *(unsigned int *)dst = pixel.color;
}*/

void	print_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	//printf("pixel x: %d\ty: %d\n", x, y);
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

/*void	print_square(t_data *data, t_square *square)
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
}*/
