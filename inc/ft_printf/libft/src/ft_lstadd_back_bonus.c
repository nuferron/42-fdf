/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:53:45 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/16 16:09:19 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	if (!new)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = new;
		return (new);
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
	return (new);
}
