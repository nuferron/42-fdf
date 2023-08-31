#ifndef FDF_H
# define FDF_H

#include "minilibx/mlx.h"
#include "include/ft_printf/libftprintf.h"
#include "include/ft_printf/libft/libft.h"
#include <stdlib.h>
#include <math.h>

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
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

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	float	t;
	float	r;
	float	g;
	float	b;
	unsigned int		color;
}				t_point;

typedef struct	s_xiaolin
{
	float	x1;
	float	x2;
	float	y;
	float	xend;
	float	yend;
	float	xgap;
	float	gradient;
	float	intery;
}				t_xiaolin;

void			print_pixel(t_data *data, int x, int y, int color);
unsigned int	trgb_to_hex(int t, int r, int g, int b);
void			print_square(t_data *data, t_square *square);
void			print_line(t_data *data, t_point *origin, t_point *fin);
float			ft_abs(float num);
float			getting_float(float num);
int				ft_round(float num);
//unsigned int	color(t_data *data, int t, int r, int g, int b);
int				file_type(char *path);
int				error_management(char *path);
void			read_map(int fd, t_data *data);
unsigned int	getting_color(char *str);

#endif
