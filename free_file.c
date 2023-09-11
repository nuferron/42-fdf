#include "fdf.h"

void	free_matrix(t_structs all, char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < all.max_row)
		free(matrix[i++]);
	free(matrix);
}

void	free_list(t_structs *all, t_list *lst)
{
	t_list	*tmp;
	int i;

	i = all->max_col;

	if (!lst)
		return ;
	while (lst)
	{
		free(lst->content);
		tmp = lst->next;
		free(lst);
		lst  = tmp;
	}
}

void	*free_them_all(t_structs all, char **mat, t_list *lst, t_point *p)
{
	free_matrix(all, mat);
	free_list(&all, lst);
	free(p);
	ft_printf("Uh-oh! There seems to be memory problems!\n");
	return (NULL);
}
