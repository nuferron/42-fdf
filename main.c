#include "minilibx/mlx.h"
#include <stdlib.h>

typedef struct	s_win
{
	void	*mlx_init;
	void	*mlx_wdw;
	int		height;
	int		width;
}	t_win;

typedef struct	s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		endian;
	int		line_len
}				t_img;


int	main()
{
	t_win	*win;

	win = (t_win *)malloc(sizeof(t_win));
	if (!win)
		return (-1);
	win->mlx_init = mlx_init();
	if (!win->mlx_init)
		return (-1);
	win->height = 400;
	win->width = 600;
	win->mlx_wdw = mlx_new_window(win->mlx_init, win->width, win->height, "FDF");
	if (!win->mlx_wdw)
		return (-1);
	mlx_loop(win->mlx_wdw);
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
