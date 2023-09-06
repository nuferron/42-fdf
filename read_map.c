#include "fdf.h"

//while mapa
//	llegir linia
//		while linia
//			guardar coordenades
//			if len > 1
//				color = split(punt, ',')
//				point.color = color[1]
//			else
//				point.color = default
//			if error
//				free all
//				return ;
//			linia++
//	mapa++
//return points

char	*getting_row(t_structs *all, int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_wordcount(line, ' ');
	if (all->max_col != 0 && all->max_col != len)
	{
		ft_printf("Watch out! This map is irregular!\n");
		return (NULL);
	}
	all->max_col = len;
	return (line);
}

t_point	*getting_row_points(t_structs all, char **coords)
{
	t_point	*row_points;
	int		col;
	char	**color;

	col = 0;
	row_points = (t_point *)malloc(sizeof(t_point) * all.max_col);
	if (!row_points)
		return (NULL);
	while (col < all.max_col)
	{
		row_points[col].x = col;
		row_points[col].y = all.max_row;
		row_points[col].z = ft_atoi(coords[col]);
		color = ft_split(coords[col], ',');
		if (!color)
		{
			//free them all
			free_them_all(all, color, 0, 0);
			//ft_printf("Uh-oh there seems to be some memory problems\n");
			return (NULL);
		}
		if (color[1])
			row_points[col].color = getting_color(color[1]);
		else
			row_points[col].color = 0x00FF0000;
		col++;
	}
	return (row_points);
}

t_list	*read_map(int fd, t_structs *all)
{
	t_list	*map;
	t_list	*tmp;
	t_point	*points;
	char	*row;
	char	**coords;

	all->max_col = 0;
	all->max_row = 0;
	map = NULL;
	while (1)
	{
		row = getting_row(all, fd);
		if (!row)
			break ;
		coords = ft_split(row, ' ');
		if (!coords)
		{
			//free them all
			//ft_printf("Uh-oh there seems to be some memory problems\n");
			return ((t_list *)free_them_all(*all, coords, map, points));
		}
		points = getting_row_points(*all, coords);
		if (!points)
		{
			//free them all
			//ft_printf("Uh-oh there seems to be some memory problems\n");
			return ((t_list *)free_them_all(*all, coords, map, points));
		}
		tmp = ft_lstnew(points);
		if (!tmp)
		{
			//free them all
			//ft_printf("Uh-oh there seems to be some memory problems\n");
			return ((t_list *)free_them_all(*all, coords, map, points));
		}
		ft_lstadd_back(&map, tmp);
		all->max_row++;
	}
	return (map);
}
