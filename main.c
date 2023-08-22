#include "fdf.h"
#include <stdio.h>
#include <math.h>

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_square	square;
	t_point		origin;
	t_point		final;

	mlx = mlx_init();
	if (argc != 5)
		return (ft_printf("Invalid number of arguments"));
	mlx_win = mlx_new_window(mlx, 300, 300, "hellow");
	img.img = mlx_new_image(mlx, 300, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	square.x = 10;
	square.y = 10;
	square.dim = 10;
	square.color = 0x00FF0000;
	print_square(&img, &square);
	origin.x = atoi(argv[1]);
	origin.y = atoi(argv[2]);
	final.x = atoi(argv[3]);
	final.y = atoi(argv[4]);
	origin.color = 0x00FF0000;
	final.color = 0x00FF0000;
	printf("origin:\tx= %f\ty= %f\nfinal:\tx= %f\ty= %f\n\n", origin.x, origin.y, final.x, final.y);
	print_line(&img, origin, final);
	print_pixel(&img, origin.x, origin.y, 0x0000FF00);
	print_pixel(&img, final.x, final.y, 0x0000FF00);
	//print_pixel(&img, 150, 150, 0x0000FF00);
	//print_pixel(&img, 150, 200, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
