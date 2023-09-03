#include "fdf.h"
#include <stdio.h>
#include <math.h>

t_point	*create_cube(t_data data)
{
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	d;
	t_point	e;
	t_point	f;
	t_point	g;
	t_point	h;
	t_point	*map;

	a.x = 10;
	a.y = 10;
	a.z = 0;
	a.color = 0x00FF00;

	b.x = 50;
	b.y = 10;
	b.z = 0;
	b.color = 0xFF0000;

	c.x = 10;
	c.y = 50;
	c.z = 0;
	c.color = 0x0000FF;

	d.x = 50;
	d.y = 50;
	d.z = 0;
	d.color = 0x00FFFF;

	e.x = 30;
	e.y = 30;
	e.z = 0;
	e.color = 0xFFFF00;

	f.x = 70;
	f.y = 30;
	f.z = 0;
	f.color = 0xFF00FF;

	g.x = 30;
	g.y = 70;
	g.z = 0;
	g.color = 0x00FF00;

	h.x = 70;
	h.y = 70;
	h.z = 0;
	h.color = 0x00FF00;

	print_line(&data, a, b);
	print_line(&data, a, c);
	print_line(&data, a, e);
	print_line(&data, b, f);
	print_line(&data, b, d);
	print_line(&data, c, d);
	print_line(&data, c, g);
	print_line(&data, d, h);
	print_line(&data, e, f);
	print_line(&data, e, g);
	print_line(&data, f, h);
	print_line(&data, g, h);

	map = (t_point *)malloc(sizeof(t_point) * 8);
	map[0] = a;
	map[1] = b;
	map[2] = c;
	map[3] = d;
	map[4] = e;
	map[5] = f;
	map[6] = g;
	map[7] = h;
	return (map);
}


/*int	close_win(t_data *data)
{
	if (data)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
}*/

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

int	update_cube(t_structs *all)
{	
	go_black(all->data);
	print_line(all->data, all->point[0], all->point[1]);
	print_line(all->data, all->point[0], all->point[2]);
	print_line(all->data, all->point[0], all->point[4]);
	print_line(all->data, all->point[1], all->point[5]);
	print_line(all->data, all->point[1], all->point[3]);
	print_line(all->data, all->point[2], all->point[3]);
	print_line(all->data, all->point[2], all->point[6]);
	print_line(all->data, all->point[3], all->point[7]);
	print_line(all->data, all->point[4], all->point[5]);
	print_line(all->data, all->point[4], all->point[6]);
	print_line(all->data, all->point[5], all->point[7]);
	print_line(all->data, all->point[6], all->point[7]);
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, all->data->img, 0, 0);
	return (0);
}

void	translation(t_structs *all, int key)
{
	int	i = 0;

	while (i < 8)
	{
		if (key == RIGHT)
			all->point[i].x = all->point[i].x + 10;
		else if (key == LEFT)
			all->point[i].x = all->point[i].x - 10;	
		else if (key == UP)
			all->point[i].y = all->point[i].y - 10;	
		else if (key == DOWN)
			all->point[i].y = all->point[i].y + 10;
		i++;
	}
	update_cube(all);
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
	m_y = 2;
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

	printf("read_keys %p\n", all);
	if (key == ESC || key == Q)
		close_win(all->data);
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		translation(all, key);
	return (0);
}

int	tutorial(int x, int y, t_structs *all)
{
	(void)all;
	printf("mouse x %d\ty %d\n", x, y);
	return (0);
}

int	main(void)
{
	t_data	data;
	t_point	*map;
	t_structs	all;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIN_MAX, WIN_MAX, "Proves");
	data.img = mlx_new_image(data.mlx, WIN_MAX, WIN_MAX);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);

	map = create_cube(data);
	//printf("main x %f\ty %f\t z %f\n", map[0].x, map[0].y, map[0].z);

	all.data = &data;
	all.point = map;
	//printf("x %f\ty %f\tz %f\n%p\n", all.point[0].x, all.point[0].y, all.point[0].z, &all);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	mlx_hook(data.mlx_win, 6, 0, tutorial, &all);
	mlx_hook(data.mlx_win, 2, 0, read_keys, &all);
	mlx_hook(data.mlx_win, 4, 0, read_mouse, &all);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(all.data->mlx);
}
