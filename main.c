#include "fdf.h"
#include <stdio.h>
#include <math.h>

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

int	close_win(t_structs *all)
{
	if (all->data)
		mlx_destroy_window(all->data->mlx, all->data->mlx_win);
	free_list(all, all->map);
	//free_them_all(*all, 0, all->map, 0);
	//necessito fer free sense que m'imprimeixi l'error. a mes crec que no estic alliberant be el map!
	exit(EXIT_SUCCESS);
}

int	read_mouse(int zoom, int m_x, int m_y, t_structs *all)
{
	(void)m_x;
	(void)m_y;
	if (zoom == SCROLL_UP)
		all->design->zoom *= 1.5;
	else if (zoom == SCROLL_DOWN)
	{
		if (all->design->zoom > 1)
			all->design->zoom /= 1.5;
	}
	update_map(all);
	return (0);
}

int	read_keys(int key, t_structs *all)
{
	if (key == ESC || key == Q)
		close_win(all);
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		translation(all, key);
	else if (key == X || key == Y || key == Z)
		rotation(all, key);
	else if (key == ISO || key == PAN || key == BIRDY)
		projection(all, key);
	else if (key == RESTART)
		restart(all);
	return (0);
}

/*int	tutorial(int x, int y, t_structs *all)
{
	(void)all;
	printf("mouse x %d\ty %d\n", x, y);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_data		data;
	t_design	design;
	t_structs	all;
	t_angle		angle;
	t_list		*map;
	int			fd;

	if (argc != 2)
		return (ft_printf("Invalid number of arguments!\n"));
	fd = error_management(argv[1]);
	if (fd == -1)
		return (-1);
	map = read_map(fd, &all);
	if (!map)
		return (-1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, MAX_X, MAX_Y, "Proves");
	data.img = mlx_new_image(data.mlx, MAX_X, MAX_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);

	all.design = &design;
	angle.x = 0;
	angle.y = 0;
	angle.z = 0;
	all.data = &data;
	all.angle = angle;
	restart(&all);

	all.map = map;
	update_map(&all);
	mlx_hook(data.mlx_win, 17, 0, close_win, &all);
	mlx_hook(data.mlx_win, 2, 0, read_keys, &all);
	mlx_hook(data.mlx_win, 4, 0, read_mouse, &all);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(all.data->mlx);
}
