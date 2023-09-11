/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:06:22 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/11 21:31:02 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation(t_structs *all, int key)
{
	if (key == RIGHT)
		all->design->pox += 50;
	else if (key == LEFT)
		all->design->pox -= 50;
	else if (key == UP)
		all->design->poy -= 50;
	else if (key == DOWN)
		all->design->poy += 50;
	update_map(all);
}

void	projection(t_structs *all, int key)
{
	if (key == ISO)
	{
		all->design->rotx = 1;
		all->design->roty = 0;
		all->design->rotz = 1;
	}
	else if (key == PAN)
	{
		all->design->rotx = 5;
		all->design->roty = 0;
		all->design->rotz = 0;
	}
	else if (key == BIRDY)
	{
		all->design->rotx = 0;
		all->design->roty = 0;
		all->design->rotz = 0;
	}
	update_map(all);
}

void	restart(t_structs *all)
{
	ft_printf("restart\n");
	all->design->zoom = MAX_X / (all->max_col * 2);
	all->design->rotx = 1;
	all->design->roty = 0;
	all->design->rotz = 1;
	all->design->pox = (int)(MAX_X / 2);
	all->design->poy = (int)(MAX_Y / 2);
	update_map(all);
}
