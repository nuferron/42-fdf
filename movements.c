#include "fdf.h"

void	translation(t_structs *all, int key)
{
	if (key == RIGHT)
		all->pox += 10;
	else if (key == LEFT)
		all->pox -= 10;
	else if (key == UP)
		all->poy -= 10;
	else if (key == DOWN)
		all->poy += 10;
	update_map(all);
}

void	rotation_x(t_structs *all, t_point *origin, t_point *final)
{
	float	y;
	float	cosinus;
	float	sinus;

	cosinus = cos(PI / 9 * all->rotx);
	sinus = sin(PI / 9 * all->rotx);
	if (all->rotx != 0)
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

	cosinus = cos(PI / 9 * all->roty);
	sinus = sin(PI / 9 * all->roty);
	if (all->roty != 0)
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

	cosinus = cos(PI / 9 * all->rotz);
	sinus = sin(PI / 9 * all->rotz);
	if (all->rotz != 0)
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
	{
		all->rotx += 1;
		printf("rotation x %d\n", all->rotx);
	}
	else if (key == Y)
		all->roty += 1;
	else if (key == Z)
		all->rotz += 1;
	update_map(all);
}
