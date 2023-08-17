/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:13:52 by nuferron          #+#    #+#             */
/*   Updated: 2023/02/21 21:14:22 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_list	*ft_lstnew(void *content)
{
	t_list	*var;

	var = (t_list *)malloc(sizeof(t_list));
	if (!var)
		return (NULL);
	var->content = content;
	var->next = NULL;
	return (var);
}
