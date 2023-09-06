#include "fdf.h"

t_point **create_map(t_structs *all)
{
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	d;
	t_point	e;
	t_point	f;
	t_point	g;
	t_point	h;
	t_point	i;
	t_point	**map;
	int		it;

	a.x = 10;
	a.y = 10;
	a.z = 0;
	a.color = 0x00FF00;

	b.x = 30;
	b.y = 10;
	b.z = 0;
	b.color = 0xFF0000;

	c.x = 50;
	c.y = 10;
	c.z = 0;
	c.color = 0x0000FF;

	d.x = 10;
	d.y = 30;
	d.z = 0;
	d.color = 0x00FFFF;

	e.x = 30;
	e.y = 30;
	e.z = 30;
	e.color = 0xFFFF00;

	f.x = 50;
	f.y = 30;
	f.z = 0;
	f.color = 0xFF0000;

	g.x = 10;
	g.y = 50;
	g.z = 0;
	g.color = 0x00FF00;

	h.x = 30;
	h.y = 50;
	h.z = 0;
	h.color = 0x00FF00;

	i.x = 50;
	i.y = 50;
	i.z = 0;
	i.color = 0x00FF00;

	map = (t_point **)malloc(sizeof(t_point *) * all->max_row);
	if (!map)
		return (NULL);
	it = 0;
	while (it < all->max_col)
	{
		map[it] = (t_point *)malloc(sizeof(t_point) * all->max_col);
		if (!map[it])
			return (NULL);
		it++;
	}
	map[0][0] = a;
	map[0][1] = b;
	map[0][2] = c;
	map[1][0] = d;
	map[1][1] = e;
	map[1][2] = f;
	map[2][0] = g;
	map[2][1] = h;
	map[2][2] = i;
	all->map = map;
	update_map(all);
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, all->data->img, 0, 0);
	return (map);
}

void	update_map(t_structs *all)
{
	int	i;
	int	j;

	i = 0;
	go_black(all->data);
	while (i < all->max_row)
	{
		j = 0;
		while (j < all->max_col)
		{
			if (j + 1 < all->max_col)
				print_line(all, all->map[i][j], all->map[i][j + 1]);
			if (i + 1 < all->max_row)
				print_line(all, all->map[i][j], all->map[i + 1][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, all->data->img, 0, 0);
}
