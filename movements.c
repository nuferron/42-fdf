#include "fdf.h"

void	translation(t_structs *all, int key)
{
	if (key == RIGHT)
		all->pox += 10;
	else if (key == LEFT)
		all->pox -= 10;
	else if (key == UP)
		all->poy -= 10;
	else if (key == DOWN)
		all->poy += 10;
	update_map(all);
}

/*void	rotation_x(t_structs *all)
{
	int		i;
	t_list	*tmp;
	float	y;

	while (i < all->max_row)
	{
		j = 0;
		while (j < all->max_col)
		{
			y = all->map[i][j].y;
			all->map[i][j].y = y * cos(PI / 9) - z * sin(PI / 9);
			all->map[i][j].z = y * sin(PI / 9) + z * cos(PI / 9);
			j++;
		}
		tmp->next
	}
	all->angle.x += PI / 9;
	if (all->angle.x >= 2 * PI)
		all->angle.x -= 2 * PI;
}

void	rotation_y(t_structs *all)
{
	int		i;
	int		j;
	float	x;

	i = 0;
	while (i < all->max_row)
	{
		j = 0;
		while (j < all->max_col)
		{
			x = all->map[i][j].x;
			all->map[i][j].x = x * cos(PI / 9) + z * sin(PI / 9);
			all->map[i][j].z = -x * sin(PI / 9) + z * cos(PI / 9);
			j++;
		}
		i++;
	}
	all->angle.x += PI / 9;
	if (all->angle.x >= 2 * PI)
		all->angle.x -= 2 * PI;
}

void	rotation_z(t_structs *all)
{
	int		i;
	int		j;
	float	x;

	i = 0;
	while (i < all->max_row)
	{
		j = 0;
		while (j < all->max_col)
		{
			x = all->map[i][j].x;
			all->map[i][j].x = x * cos(PI / 9) - y * sin(PI / 9);
			all->map[i][j].y = x * sin(PI / 9) + y * cos(PI / 9);
			j++;
		}
		i++;
	}
	all->angle.x += PI / 9;
	if (all->angle.x >= 2 * PI)
		all->angle.x -= 2 * PI;
}

void	rotation(t_structs *all, int key)
{
	if (key == X)
		rotation_x(all);
	else if (key == Y)
		rotation_y(all);
	else if (key == Z)
		rotation_z(all);
	update_map(all);
}*/
