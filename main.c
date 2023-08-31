#include "fdf.h"
#include <stdio.h>
#include <math.h>

int	close_win(t_data *data)
{
	if (data)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
}

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

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	
	if (argc != 2)
		return (ft_printf("Invalid number of arguments\n"));
	fd = error_management(argv[1]);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1300, 1300, "FDF");
	data.img = mlx_new_image(data.mlx, 1300, 1300);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_len, &data.endian);
	read_map(fd, &data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 17, 1L<<0, close_win, &data);
	mlx_loop(data.mlx);
}
