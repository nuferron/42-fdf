#ifndef FDF_H
# define FDF_H

#include "minilibx/mlx.h"
#include "include/ft_printf/libftprintf.h"
#include "include/ft_printf/libft/libft.h"
#include <stdlib.h>
#include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct	s_square
{
	int	x;
	int	y;
	int	dim;
	int	color;
}				t_square;

typedef struct	s_line
{
	int	xo;
	int	yo;
	int	xf;
	int	yf;
	int	color;
}				t_line;

void	print_pixel(t_data *data, int x, int y, int color);
void	print_square(t_data *data, t_square *square);

#endif
