#include "fdf.h"
#include <stdio.h>
#include <math.h>

/*int	main(int argc, char **argv)
{
	t_data	win;
	t_point	origin;
	t_point	final;

	win.mlx = mlx_init();
	if (argc != 5)
		return (ft_printf("Invalid number of arguments"));
	win.mlx_win = mlx_new_window(win.mlx, 1300, 1300, "xchtrb");
	win.img = mlx_new_image(win.mlx, 1300, 1300);
	win.addr = mlx_get_data_addr(win.img, &win.bpp, &win.line_len, &win.endian);
	origin.x = atoi(argv[1]);
	origin.y = atoi(argv[2]);
	final.x = atoi(argv[3]);
	final.y = atoi(argv[4]);
	//file_type(argv[5]);
	print_line(&win, &origin, &final);
	//color(&win, 0, 255, 255, 0);
	//print_pixel(&win, 499, 499, 0x00FF00);
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img, 0, 0);
	mlx_hook(win.mlx_win, 17, 1L<<0, close_win, &win);
	mlx_loop(win.mlx);
}*/

/*int	main(int argc, char **argv)
{
	t_data	data;
	int		error;
	
	if (argc != 2)
		return (ft_printf("Invalid number of arguments\n"));
	error = error_management(argv[1]);
	if (error != 0)
		return (-1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1300, 1300, "FDF");
	data.img = mlx_new_image(data.mlx, 1300, 1300);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	read_map(fd, &data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 17, 1L<<0, close_win, &data);
	mlx_loop(data.mlx);
}*/

void	go_black(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 1300)
	{
		y = 0;
		while (y < 1300)
		{
			print_pixel(data, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

int	close_win(t_data *data)
{
	if (data)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
}

int	read_mouse(int zoom, int m_x, int m_y, t_structs *all)
{
	int	i = 0;
	m_x = 0;
	m_y = 0;
	if (zoom == SCROLL_UP)
	{
		while (i < 8)
		{
			all->point[i].x = all->point[i].x * 1.5;
			all->point[i].y = all->point[i].y * 1.5;
			i++;
		}
	}
	else if (zoom == SCROLL_DOWN)
	{
		while (i < 8)
		{
			all->point[i].x = all->point[i].x / 1.5;
			all->point[i].y = all->point[i].y / 1.5;
			i++;
		}
	}
	update_cube(all);
	return (0);
}

int	read_keys(int key, t_structs *all)
{
	//printf("key = %d\n", key);
	if (key == ESC || key == Q)
		close_win(all->data);
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		translation(all, key);
	else if (key == X || key == Y || key == Z)
		rotation(all, key);
	return (0);
}

int	tutorial(int x, int y, t_structs *all)
{
	(void)all;
	printf("mouse x %d\ty %d\n", x, y);
	return (0);
}

/*int	main(void)
{
	t_data	data;
	t_structs	all;
	t_angle		angle;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, MAX_X, MAX_Y, "Proves");
	data.img = mlx_new_image(data.mlx, MAX_X, MAX_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);

	all.max_row = 3;
	all.max_col = 3;
	angle.x = 0;
	angle.y = 0;
	angle.z = 0;
	all.data = &data;
	all.angle = angle;
	//create_cube(&all);
	create_map(&all);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	//mlx_hook(data.mlx_win, 6, 0, tutorial, &all);
	mlx_hook(data.mlx_win, 2, 0, read_keys, &all);
//	mlx_hook(data.mlx_win, 4, 0, read_mouse, &all);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(all.data->mlx);
}*/

int	main(int argc, char **argv)
{
	t_data		data;
	t_structs	all;
	t_angle		angle;
	int			fd;

	if (argc != 2)
		return (ft_printf("Invalid number of arguments!\n"));
	fd = error_management(argv[1]);
	if (fd == -1)
		return (-1);
	read_map(fd, &all);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, MAX_X, MAX_Y, "Proves");
	data.img = mlx_new_image(data.mlx, MAX_X, MAX_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);

	angle.x = 0;
	angle.y = 0;
	angle.z = 0;
	all.data = &data;
	all.angle = angle;

	//create_cube(&all);
	create_map(&all);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	//mlx_hook(data.mlx_win, 6, 0, tutorial, &all);
	mlx_hook(data.mlx_win, 2, 0, read_keys, &all);
//	mlx_hook(data.mlx_win, 4, 0, read_mouse, &all);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(all.data->mlx);
}
