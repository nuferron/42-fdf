#include "fdf.h"

void	update_map(t_structs *all)
{
	int	row;
	int	col;
	t_list *tmp;

	row = 0;
	tmp = all->map;
	go_black(all->data);
	while (row < all->max_row)
	{
		col = 0;
		while (col < all->max_col)
		{
			if (col + 1 < all->max_col)
				print_line(all, ((t_point *)(tmp->content))[col], ((t_point *)(tmp->content))[col + 1]);
			if (row + 1 < all->max_row)
				print_line(all, ((t_point *)(tmp->content))[col], ((t_point *)(tmp->next->content))[col]);
			col++;
		}
		tmp = tmp->next;
		row++;
	}
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, all->data->img, 0, 0);
}
