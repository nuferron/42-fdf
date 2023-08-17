#include "fdf.h"
#include <stdio.h>
#include <math.h>

void	straight_line(t_data *data, t_line *line)
{
	int	i;

	i = 0;
	if (line->xo != line->xf)
	{
		while (i < line->xf)
		{
			print_pixel(data, line->xo, line->yo, color);
			(line->xo)++;
			i++;
		}
	}
	else
	{
		while (line->yo != line->yf)
		{
			print_pixel(data, line->xo, line->yo, color);
			(line->yo)++;
			i++;
		}
	}
}

int	is_consec(int num1, int num2)
{
	if (num1 + 1 == num2 || num1 - 1 == num2)
		return (1);
	else
		return(0);
}

/*int	is_around(t_line *line)
{
	if (line->xo == line->xf && line->yo == line->yf)
		return (0);
	if (is_consec(line->xo, line->xf) && is_consec(line->yo, line->yf))
	{
		if (line->yo + 1 == line->yf)
			return (1);
		else if (line->yo - 1 == line->yf)
			return (1);
	}
	else if (line->yo == line->yf)
	{
		if (line->xo + 1 == line->xf)
			return(1);
		else if (line->xo - 1 == line->xf)
			return (1);
	}
	else if (line->xo + 1)
}*/

void	bresenham_algorithm(t_data *data, t_line *line)
{
	int	a;
	int	b;
	int	p;

	a = 2 * (line->yo - line->yf);
	b = a - 2 * (line->xo - line->xf);
	while (!is_consec(line->xo, line->xf) && !is_consec(line->yo, line->yf))
	{
		p = a - line->xo - line->xf;
		if ((line->xo - line->xf) * (line->yo - line->yf) < 0)
		{
			if ((line->xo - line->xf) > (line->yo - line->yf) && p < 0)
				print_pixel(data, ++(line->xo), line->yo, color);
			else
				print_pixel(data, ++(line->xo), --(line->yo), color);
		}
		else if ((line->xo - line->xf) * (line->yo - line->yf) > 0)
		{
			if (p < 0)
				print_pixel(data, ++(line->xo), line->yo, color);
			else
				print_pixel(data, ++(line->xo), --(line->yo), color);
		}
	}
}

void	print_line(t_data *data, t_line *line)
{
	if (line->xo == line->xf || line->yo == line->yf)
		straight_line(data, line);
	else if ((line->xo - line->xf) > (line->yo - line->yf))
	{
		
	}
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_square	square;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 300, "hellow");
	img.img = mlx_new_image(mlx, 300, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	square.x = 10;
	square.y = 10;
	square.dim = 10;
	square.color = 0x00FF0000;
	print_square(&img, &square);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
