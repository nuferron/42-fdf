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

void	read_map(int fd, t_data *data)
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

	color = ft_split(points[0], ',');
	if (!color)
	{
		//free them all
		ft_printf("Uh-oh malloc error\n");
		exit(-1);
	}
	color_sep = find_sep(points[0], ',');
	printf("hi ha coma? %d\ncolor: %s\n", color_sep, points[0]);
	if (color_sep != -1)
	{
		color = ft_split(points[0], ',');
		if (!color)
		{
			//free them all
			ft_printf("Uh-oh malloc error\n");
			exit(-1);
		}
		point->color = (unsigned int)&color[1][color_sep];
	}
	else
		point->color = 0xFF0000;
	print_pixel(data, 300, 300, point->color);
	printf("x %f\t y %f\tz %f\ncolor %d\n", point->x, point->y, point->z, point->color);
}
