/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:28:25 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 23:32:09 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	finding_enter(char *buffer)
{
	int	enter;

	if (buffer == NULL)
		return (-1);
	enter = 0;
	while (buffer[enter] != '\n' && buffer[enter] != '\0')
		enter++;
	if (buffer[enter] == '\0')
		return (-1);
	return (enter);
}

char	*gnl_strjoin(char *storage, char *buffer)
{
	int		tlen;
	int		i;
	char	*new_storage;

	i = 0;
	tlen = ft_strlen(storage) + ft_strlen(buffer);
	new_storage = (char *) malloc(sizeof(char) * (tlen + 1));
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	while (storage && storage[i] != '\0')
	{
		new_storage[i] = storage[i];
		i++;
	}
	while (buffer && i <= tlen)
	{
		new_storage[tlen] = buffer[tlen - i];
		tlen--;
	}
	free(storage);
	return (new_storage);
}
