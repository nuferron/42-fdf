/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:29:06 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/16 15:54:25 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tlen;
	int		i;
	char	*result;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	tlen = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	result = (char *) malloc(sizeof(char) * tlen + 1);
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (i <= tlen)
	{
		result[tlen] = s2[tlen - i];
		tlen--;
	}
	return (result);
}
