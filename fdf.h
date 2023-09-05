#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "include/ft_printf/libftprintf.h"
# include "include/ft_printf/libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include "macros.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_square
{
	int	x;
	int	y;
	int	dim;
	int	color;
}				t_square;

typedef struct s_point
{
	float				x;
	float				y;
	float				z;
	unsigned int		color;
}				t_point;

typedef struct s_xiaolin
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
	int		ax;
	int		ay;
	int		bx;
	int		by;
}				t_xiaolin;

typedef struct s_angle
{
	float	x;
	float	y;
	float	z;
}				t_angle;

typedef struct s_structs
{
	t_data		*data;
	t_point		*point;
	t_xiaolin	wu;
	int			max_col;
	int			max_row;
	t_angle		angle;
	t_point		**map;
}				t_structs;

void			print_pixel(t_data *data, int x, int y, int color);
unsigned int	trgb_to_hex(int t, int r, int g, int b);
void			print_square(t_data *data, t_square *square);
void			print_line(t_structs *all, t_point origin, t_point final);
float			ft_abs(float num);
float			getting_float(float num);
int				ft_round(float num);
int				file_type(char *path);
int				error_management(char *path);
void			read_map(int fd, t_structs *all);
unsigned int	getting_color(char *str);
void			translation(t_structs *all, int key);
void			rotation(t_structs *all, int key);
void			update_cube(t_structs *all);
t_point			*create_cube(t_structs *all);
void			update_map(t_structs *all);
t_point			**create_map(t_structs *all);
void			go_black(t_data *data);

#endif
