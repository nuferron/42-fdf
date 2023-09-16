/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:01:42 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/14 16:12:50 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	swap_coord(t_point *origin, t_point *final, int diff)
{
	t_point	tmp;

	if (diff)
	{
		tmp = *origin;
		origin->x = origin->y;
		origin->y = tmp.x;
		tmp = *final;
		final->x = final->y;
		final->y = tmp.x;
	}
	if (origin->x > final->x)
	{
		tmp = *origin;
		origin->x = final->x;
		origin->y = final->y;
		final->x = tmp.x;
		final->y = tmp.y;
	}
}

void	put_on_place(t_point *origin, t_point *final, t_structs *all)
{
	rotation_x(all, origin, final);
	rotation_y(all, origin, final);
	rotation_z(all, origin, final);
	origin->x = origin->x * all->design->zoom + all->design->pox;
	origin->y = origin->y * all->design->zoom + all->design->poy;
	final->x = final->x * all->design->zoom + all->design->pox;
	final->y = final->y * all->design->zoom + all->design->poy;
}

void	initialize_wu(t_xiaolin *wu, t_point point, int num)
{
	wu->xend = ft_round(point.x);
	if (num == 1)
	{
		wu->yend = (int)point.y + wu->gradient * (wu->xend - point.x);
		wu->xgap = 1 - getting_float(point.x + 0.5);
		wu->x1 = wu->xend;
		wu->colo = point.color;
	}
	else
	{
		wu->intery = wu->yend + wu->gradient;
		wu->yend = point.y + wu->gradient * (wu->xend - point.x);
		wu->xgap = getting_float(point.x + 0.5);
		wu->x2 = wu->xend;
		wu->colf = point.color;
	}
	wu->y = (int)wu->yend;
}
