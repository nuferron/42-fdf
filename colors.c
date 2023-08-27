#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int color(t_data *data, int t, int r, int g, int b)
{
	int	color2;

	color2 = create_trgb(t, r, g, b);
	print_pixel(data, 500, 500, color2);
	print_pixel(data, 501, 500, color2);
	print_pixel(data, 501, 501, color2);
	print_pixel(data, 500, 501, color2);
	return ((unsigned int)color);
}
