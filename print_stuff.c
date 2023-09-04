#include "fdf.h"

unsigned int trgb_to_hex(int t, int r, int g, int b) {
    return ((t & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

void	print_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MAX_X)
	{
		//printf("x error %d\n", x);
		return ;
	}
	if (y < 0 || y >= MAX_Y)
	{
		//printf("y error %d\n", y);
		return ;
	}
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
