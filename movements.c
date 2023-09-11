#include "fdf.h"

void	translation(t_structs *all, int key)
{
	if (key == RIGHT)
		all->design->pox += 30;
	else if (key == LEFT)
		all->design->pox -= 30;
	else if (key == UP)
		all->design->poy -= 30;
	else if (key == DOWN)
		all->design->poy += 30;
	update_map(all);
}

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

void	height(t_structs *all, int key)
{
	if (key == PLUS)
		all->design->height += 1;
	else if (key == MINUS)
		all->design->height -= 1;
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
	all->design->zoom = MAX_X / (all->max_col * 2);
	all->design->rotx = 1;
	all->design->roty = 0;
	all->design->rotz = 1;
	all->design->pox = (int)(MAX_X / 2);
	all->design->poy = (int)(MAX_Y / 2);
	update_map(all);
}
