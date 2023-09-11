/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:01:14 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/11 21:31:48 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MAX_X)
		return ;
	if (y < 0 || y >= MAX_Y)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	update_map(t_structs *all)
{
	int		row;
	int		col;
	t_list	*tmp;

	ft_printf("update map\n");
	row = 0;
	tmp = all->map;
	go_black(all->data);
	while (row < all->max_row)
	{
		col = 0;
		while (col < all->max_col)
		{
			if (col + 1 < all->max_col)
				print_line(all, ((t_point *)(tmp->content))[col], \
						((t_point *)(tmp->content))[col + 1]);
			if (row + 1 < all->max_row)
				print_line(all, ((t_point *)(tmp->content))[col], \
						((t_point *)(tmp->next->content))[col]);
			col++;
		}
		tmp = tmp->next;
		row++;
	}
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, \
			all->data->img, 0, 0);
}

void	go_black(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < MAX_X)
	{
		y = 0;
		while (y < MAX_Y)
			print_pixel(data, x, y++, 0x000000);
		x++;
	}
}
