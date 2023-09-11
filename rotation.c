/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:06:31 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/11 20:06:32 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_structs *all, t_point *origin, t_point *final)
{
	float	y;
	float	cosinus;
	float	sinus;

	cosinus = cos(PI / 10 * all->design->rotx);
	sinus = sin(PI / 10 * all->design->rotx);
	if (all->design->rotx != 0)
	{
		y = origin->y;
		origin->y = (y * cosinus - origin->z * sinus);
		origin->z = (y * sinus + origin->z * cosinus);
		y = final->y;
		final->y = (y * cosinus - final->z * sinus);
		final->z = (y * sinus + final->z * cosinus);
	}
}

void	rotation_y(t_structs *all, t_point *origin, t_point *final)
{
	float	x;
	float	cosinus;
	float	sinus;

	cosinus = cos(PI / 10 * all->design->roty);
	sinus = sin(PI / 10 * all->design->roty);
	if (all->design->roty != 0)
	{
		x = origin->x;
		origin->x = (x * cosinus + origin->z * sinus);
		origin->z = (-x * sinus + origin->z * cosinus);
		x = final->x;
		final->x = (x * cosinus + final->z * sinus);
		final->z = (-x * sinus + final->z * cosinus);
	}
}

void	rotation_z(t_structs *all, t_point *origin, t_point *final)
{
	float	x;
	float	cosinus;
	float	sinus;

	cosinus = cos(PI / 10 * all->design->rotz);
	sinus = sin(PI / 10 * all->design->rotz);
	if (all->design->rotz != 0)
	{
		x = origin->x;
		origin->x = (x * cosinus - origin->y * sinus);
		origin->y = (x * sinus + origin->y * cosinus);
		x = final->x;
		final->x = (x * cosinus - final->y * sinus);
		final->y = (x * sinus + final->y * cosinus);
	}
}

void	rotation(t_structs *all, int key)
{
	if (key == X)
		all->design->rotx += 1;
	else if (key == Y)
		all->design->roty += 1;
	else if (key == Z)
		all->design->rotz += 1;
	update_map(all);
}
