#include "fdf.h"

void	read_map(int fd, t_structs *all)
{
	char	*line;
	int		len;
	char	**coords;
	int		col;
	int		row;
	t_point	*point_line;
	char	**color;
	t_list	*tmp;
	t_list	*map;

	all->max_col = 0;
	all->max_row = 0;
	col = 0;
	row = 0;
	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_wordcount(line, ' ');
		if (all->max_col != 0 && len != all->max_col)
		{
			//free them all
			ft_printf("Watch out! This map is irregular\n");
			exit(-1);
		}
		all->max_col = len;
		////////////////////////////////////////////////////
		coords = ft_split(line, ' ');
		if (!coords)
		{
			//free them all
			ft_printf("Uh-oh it seems to be some memory problems\n");
			exit(-1);
		}
		////////////////////////////////////////////////////
		point_line = (t_point *)malloc(sizeof(t_point) * all->max_col);
		if (!point_line)
		{
			//free them all
			ft_printf("Uh-oh it seems to be some memory problems\n");
			exit(-1);
		}
		while (col < all->max_col)
		{
			point_line[col].x = col;
			point_line[col].y = row;
			point_line[col].z = ft_atoi(coords[col]);
			color = ft_split(coords[col], ',');
			if (!color)
			{
				//free them all
				ft_printf("Uh-oh it seems to be some memory problems\n");
				exit(-1);
			}
			if (color[1])
				point_line[col].color = getting_color(color[1]);
			else
				point_line[col].color = 0x00FF0000;
			col++;
		}
		////////////////////////////////////////////////
		tmp = ft_lstnew(point_line);
		if (!tmp)
		{
			//free them all
			ft_printf("Uh-oh it seems to be some memory problems\n");
			exit(-1);
		}
		ft_lstadd_back(&map, tmp);
		all->max_row++;
	}
}
