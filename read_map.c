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

int	find_sep(char *str, char c)
{
	int	pos;

	printf("hola?\nc %c\tstr %s\n", c, str);
	if (!str)
		return (-1);
	pos = 0;
	while (str[pos] != c && str[pos] != '\0')
		pos++;
	if (str[pos] == '\0')
		return (-1);
	printf("pos= %d\n", pos);
	return (pos);
}

void	read_map(int fd, t_structs *all)
{
	char	*line;
	char	**points_lst;
	t_point	**map;
	char	**color;
	int		x;
	int		y;
	t_point	*point;

	y = 0;
	while (1)
	{
		printf("lectura %d\n", y);
		line = get_next_line(fd);
		printf("line = %s\n", line);
		if (!line)
			break ;
		all->max_col = ft_strlen(line);
		points_lst = ft_split(line, ' ');
		if (!points_lst)
		{
			//free them all
			ft_printf("Uh-oh split error\n");
		}
		x = 0;
		while (points_lst[x][1] != '\0' && points_lst[x][1] != '\n')
		{
			printf("volta %d\n", x);
			point = (t_point *)malloc(sizeof (t_point));
			if (!point)
			{
				//free them all
				ft_printf("Uh-oh malloc error\n");
				exit(-1);
			}
			point->x = x;
			point->y = y;
			point->z = ft_atoi(points_lst[x]);
			color = ft_split(points_lst[x], ',');
			printf("mitja marato\n");
			if (!color)
			{
				//free them all
				ft_printf("Uh-oh malloc error\n");
			}
			if (color[1] != NULL)
				point->color = getting_color(color[1]);
			else
				point->color = 0xFF0000;
			printf("while %c\n", points_lst[x][0]);
			map[y][x] = *point; // he de reservar memoria per map, pero encara no se quantes files tindre. Pero no passa res, perque puc reservar linies t_point * i despres a cada volta fer free + malloc o algo aixi
			x++;
		}
		y++;
	}
	//si el nombre de files son les que haurien de ser, ok si
	all->max_row = y;
	close(fd);
	int i = 0;
	int j;
	while (i < all->max_row)
	{
		j = 0;
		while (j < all->max_col)
		{
			printf("x %f\ty %f\tcolor %X\n", map[i][j].x, map[i][j].y, map[i][j].color);
			j++;
		}
		i++;
	}
}

/*void	read_map(int fd, t_data *data)
{
	char	*line;
	char	**points;
	char	**color;
	//t_point	**map;
	t_point	*point;
	int		color_sep;

	line = get_next_line(fd);
	line = ft_strdup(line);
	points = ft_split(line, ' ');
	if (!points)
	{
		//free them all
		ft_printf("Uh-oh malloc error\n");
		exit(-1);
	}
	point = (t_point *)malloc(sizeof (t_point));
	if (!point)
	{
		//free them all
		ft_printf("Uh-oh malloc error\n");
		exit(-1);
	}

	point->x = 0;
	point->y = 0;
	point->z = ft_atoi(points[0]);

	//color = ft_split(points[0], ',');
//	if (!color)
//	{
		//free them all
//		ft_printf("Uh-oh malloc error\n");
//		exit(-1);
//	}
	color_sep = find_sep(points[0], ',');
	printf("hi ha coma? %d\ncolor: %s\n", color_sep, points[0]);
	color = ft_split(points[0], ',');
	if (color[1] != NULL)
	{
		printf("Color specified\n");
	}
	else
		printf("No color specified\n");
	if (color_sep != -1)
	{
		color = ft_split(points[0], ',');
		if (!color)
		{
			//free them all
			ft_printf("Uh-oh malloc error\n");
			exit(-1);
		}
		point->color = getting_color(color[1]);
	}
	else
		point->color = 0xFF0000;
	print_pixel(data, 300, 300, point->color);
	printf("x %f\t y %f\tz %f\ncolor %X\n", point->x, point->y, point->z, point->color);
}*/
