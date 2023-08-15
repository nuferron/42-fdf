#include "minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_win
{
	void	*mlx_init;
	void	*mlx_wdw;
	int		height;
	int		width;
}	t_win;

typedef struct	s_img
{
	t_win	*win;
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;


t_win	*new_program(int width, int height, char *str)
{
	t_win	*win;

	win = (t_win *)malloc(sizeof(t_win));
	if (!win)
		return (win);
	win->mlx_init = mlx_init();
	win->mlx_wdw = mlx_new_window(win->mlx_init, width, height, str);
	if (!win->mlx_wdw)
		return (win);
	return (win);
}

int	main()
{
	t_win	*win;
	t_img	*img4;

	/*win = (t_win *)malloc(sizeof(t_win));
	if (!win)
		return (-1);
	win->mlx_init = mlx_init();
	if (!win->mlx_init)
		return (-1);
	win->height = 400;
	win->width = 600;
	win->mlx_wdw = mlx_new_window(win->mlx_init, win->width, win->height, "FDF");
	if (!win->mlx_wdw)
		return (-1);*/
	win = new_program(300, 300, "FDF");
	if (!win)
		return (-1);
	img4 = (t_img *)malloc(sizeof(t_img));
	img4->win = win;
	img4->img_ptr = mlx_new_image(win->mlx_init, 4, 4);
	img4->addr = mlx_get_data_addr(img4->img_ptr, &(img4->bpp), &(img4->line_len), &(img4->endian));
	img4->width = 4;
	img4->height = 4;
	memcpy(img4->addr, "s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf", 16*4);
	mlx_put_image_to_window(img4->win->mlx_init, img4->win->mlx_wdw,img4->img_ptr, 10, 10);
	mlx_loop(win->mlx_init);
}

/*int	main()
{
	void	*mlx_ptr;
	void	*mlx_wdw;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (-1);
	mlx_wdw = mlx_new_window(mlx_ptr, 500, 500, "FDF");
	if (!mlx_wdw)
		return (-1);
	mlx_loop(mlx_wdw);
}*/
