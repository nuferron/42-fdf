/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:03:41 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/11 21:29:20 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xiaolin_ft(t_structs *all, t_point origin, t_point final, t_xiaolin wu)
{
	initialize_wu(&wu, origin, 1);
	print_extremes(all, &wu, wu.diff, 1);
	initialize_wu(&wu, final, 2);
	print_extremes(all, &wu, wu.diff, 2);
	wu.x1++;
	print_in_between(all, wu, wu.diff);
}

void	print_extremes(t_structs *all, t_xiaolin *wu, int diff, int num)
{
	float	var;

	if (num == 1)
		var = wu->x1;
	else
		var = wu->x2;
	if (diff)
	{
		print_pixel(all->data, wu->y, var, wu->colo);
		print_pixel(all->data, wu->y + 1, var, wu->colo);
	}
	else
	{
		print_pixel(all->data, var, wu->y, wu->colo);
		print_pixel(all->data, var + 1, wu->y, wu->colo);
	}
}

void	print_in_between(t_structs *all, t_xiaolin wu, int diff)
{
	if (diff)
	{
		while (wu.x1 < wu.x2)
		{
			print_pixel(all->data, wu.intery, wu.x1, wu.colo);
			print_pixel(all->data, wu.intery + 1, wu.x1++, wu.colo);
			wu.intery += wu.gradient;
		}
	}
	else
	{
		while (wu.x1 < wu.x2)
		{
			print_pixel(all->data, wu.x1, wu.intery, wu.colo);
			print_pixel(all->data, wu.x1++, wu.intery + 1, wu.colo);
			wu.intery += wu.gradient;
		}
	}
}

void	print_line(t_structs *all, t_point origin, t_point final)
{
	float		dx;
	float		dy;
	t_xiaolin	wu;

	ft_printf("print_line\n");
	put_on_place(&origin, &final, all);
	wu.diff = ft_abs(final.y - origin.y) > ft_abs(final.x - origin.x);
	swap_coord(&origin, &final, wu.diff);
	dx = final.x - origin.x;
	dy = final.y - origin.y;
	if (dx == 0)
		wu.gradient = 1;
	else
		wu.gradient = dy / dx;
	xiaolin_ft(all, origin, final, wu);
}
