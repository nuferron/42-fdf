#ifndef FDF_H
# define FDF_H

#include "minilibx/mlx.h"
#include "include/ft_printf/libftprintf.h"
#include "include/ft_printf/libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include "macros.h"

/*# define ESC 53 // key escape
# define LEFT 123 // left arrow
# define RIGHT 124 // right arrow
# define DOWN 125 // down arrow
# define UP 126*/

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
	float				x;
	float				y;
	float				z;
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
	int		diff;
}				t_xiaolin;

typedef struct	s_structs
{
	t_data		*data;
	t_point		*point;
	t_xiaolin	wu;
}				t_structs;

/*typedef struct	s_line
{
	char	*points;
	void	*next;
	void	*prev;
}				t_line;

typedef struct	s_map
{
	t_point	*line;
	void	*next;
	void	*prev;
}				t_map;*/

void			print_pixel(t_data *data, int x, int y, int color);
unsigned int	trgb_to_hex(int t, int r, int g, int b);
void			print_square(t_data *data, t_square *square);
void			print_line(t_data *data, t_point origin, t_point final);
float			ft_abs(float num);
float			getting_float(float num);
int				ft_round(float num);
int				file_type(char *path);
int				error_management(char *path);
void			read_map(int fd, t_data *data);
unsigned int	getting_color(char *str);

#endif
