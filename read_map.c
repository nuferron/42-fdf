/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:02:20 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/11 21:21:48 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		ft_printf("\033[1;31;mWatch out! This map is irregular!\n");
		ft_printf("\033[1;33;mOnly the regular part will be printed.\n");
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
		row_points[col].x = col - all.max_col / 2;
		row_points[col].y = all.max_row;
		row_points[col].z = ft_atoi(coords[col]);
		color = ft_split(coords[col], ',');
		if (!color)
			return (free_them_all(all, color, 0, 0));
		if (color[1])
			row_points[col].color = getting_color(color[1]);
		else
			row_points[col].color = 0x0000FF00;
		col++;
		free_matrix(all, color);
	}
	free_matrix(all, coords);
	return (row_points);
}

t_list	*correct_y(t_structs *all, t_list *map)
{
	t_list	*tmp;
	int		i;

	tmp = map;
	while (tmp)
	{
		i = 0;
		while (i < all->max_col)
			((t_point *)(tmp->content))[i++].y -= all->max_row / 2;
		tmp = tmp->next;
	}
	return (map);
}

t_list	*read_map(int fd, t_structs *all)
{
	t_list	*map;
	t_point	*points;
	char	*row;
	char	**coords;

	map = NULL;
	while (1)
	{
		row = getting_row(all, fd);
		if (!row)
			break ;
		coords = ft_split(row, ' ');
		free(row);
		if (!coords)
			return ((t_list *)free_them_all(*all, coords, map, points));
		points = getting_row_points(*all, coords);
		if (!points)
			return ((t_list *)free_them_all(*all, coords, map, points));
		if (!ft_lstadd_back(&map, ft_lstnew(points)))
			return ((t_list *)free_them_all(*all, coords, map, points));
		all->max_row++;
	}
	return (correct_y(all, map));
}
