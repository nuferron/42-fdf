/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:23:15 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/14 16:14:05 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "inc/minilibx/mlx.h"
# include "inc/ft_printf/libftprintf.h"
# include "inc/ft_printf/libft/libft.h"
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

typedef struct s_point
{
	float				x;
	float				y;
	float				z;
	unsigned int		color;
}				t_point;

typedef struct s_xiaolin
{
	float			x1;
	float			x2;
	float			y;
	float			xend;
	float			yend;
	float			xgap;
	float			gradient;
	float			intery;
	int				diff;
	int				colo;
	int				colf;
}				t_xiaolin;

typedef struct s_design
{
	float	zoom;
	float	pox;
	float	poy;
	int		rotx;
	int		roty;
	int		rotz;
	int		height;
}				t_design;

typedef struct s_structs
{
	t_data		*data;
	t_point		*point;
	t_xiaolin	wu;
	int			max_col;
	int			max_row;
	t_list		*map;
	t_design	*design;
}				t_structs;

unsigned int	getting_color(char *str);
void			print_pixel(t_data *data, int x, int y, int color);
void			print_line(t_structs *all, t_point origin, t_point final);
void			go_black(t_data *data);
void			update_map(t_structs *all);

void			swap_coord(t_point *origin, t_point *final, int diff);
void			xiaolin_ft(t_structs *all, t_point o, t_point f, t_xiaolin wu);
void			put_on_place(t_point *origin, t_point *final, t_structs *all);
void			initialize_wu(t_xiaolin *wu, t_point point, int num);
void			print_extremes(t_structs *all, t_xiaolin *wu, int dif, int num);
void			print_in_between(t_structs *all, t_xiaolin wu, int diff);

float			ft_abs(float num);
float			getting_float(float num);
int				ft_round(float num);

int				file_type(char *path);
int				error_management(char *path);
t_list			*read_map(int fd, t_structs *all);

void			translation(t_structs *all, int key);
void			rotation(t_structs *all, int key);
void			rotation_x(t_structs *all, t_point *origin, t_point *final);
void			rotation_y(t_structs *all, t_point *origin, t_point *final);
void			rotation_z(t_structs *all, t_point *origin, t_point *final);
void			projection(t_structs *all, int key);
void			restart(t_structs *all);

void			free_matrix(t_structs all, char **matrix);
void			free_list(t_structs *all, t_list *lst);
void			*free_them_all(t_structs all, char **m, t_list *l, t_point *p);

#endif
