/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:25:54 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/23 14:28:50 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_win(t_structs *all)
{
	if (all->data)
		mlx_destroy_window(all->data->mlx, all->data->mlx_win);
	free_list(all, all->map);
	exit(EXIT_SUCCESS);
}

int	read_mouse(int zoom, int m_x, int m_y, t_structs *all)
{
	(void)m_x;
	(void)m_y;
	if (zoom == SCROLL_UP)
		all->design->zoom *= 1.5;
	else if (zoom == SCROLL_DOWN)
	{
		if (all->design->zoom > 1)
			all->design->zoom /= 1.5;
	}
	update_map(all);
	return (0);
}

int	read_keys(int key, t_structs *all)
{
	if (key == ESC || key == Q)
		close_win(all);
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		translation(all, key);
	else if (key == X || key == Y || key == Z)
		rotation(all, key);
	else if (key == ISO || key == PAN || key == BIRDY)
		projection(all, key);
	else if (key == RESTART)
		restart(all);
	else if (key == WHITE_BKG)
		change_background(all);
	update_map(all);
	return (0);
}

t_data	getting_data(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, MAX_X, MAX_Y, "FDF");
	data.img = mlx_new_image(data.mlx, MAX_X, MAX_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, \
			&data.line_len, &data.endian);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_design	design;
	t_structs	all;
	int			fd;

	if (argc != 2)
		return (ft_printf("\033[31;1mInvalid number of arguments!\n\033[0;m"));
	fd = error_management(argv[1]);
	if (fd == -1)
		return (-1);
	all.max_col = 0;
	all.max_row = 0;
	all.map = read_map(fd, &all);
	if (!all.map)
		return (-1);
	all.design = &design;
	data = getting_data();
	all.data = &data;
	restart(&all);
	update_map(&all);
	mlx_hook(all.data->mlx_win, 17, 0, close_win, &all);
	mlx_hook(all.data->mlx_win, 2, 0, read_keys, &all);
	mlx_hook(all.data->mlx_win, 4, 0, read_mouse, &all);
	mlx_loop(all.data->mlx);
}
