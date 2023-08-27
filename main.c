#include "fdf.h"
#include <stdio.h>
#include <math.h>

int	main(int argc, char **argv)
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
	//origin.color = trgb_to_hex(atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]));
	print_line(&win, &origin, &final);
	//print_pixel(&win, atoi(argv[1]), atoi(argv[2]), 0x00FF00);
	//print_pixel(&win, atoi(argv[3]), atoi(argv[4]), 0x00FF00);
	mlx_put_image_to_window(win.mlx, win.mlx_win, win.img, 0, 0);
	mlx_loop(win.mlx);
}
