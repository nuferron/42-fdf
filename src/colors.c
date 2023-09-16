/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:02:02 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/14 16:09:47 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hex_to_hex(char first, char second)
{
	static char	*base_hex_max = "0123456789ABCDEF";
	static char	*base_hex_min = "0123456789abcdef";
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (base_hex_max[i] != first && base_hex_min[i] != first)
		i++;
	while (base_hex_max[j] != second && base_hex_min[j] != second)
		j++;
	return (16 * i + j);
}

unsigned int	getting_color(char *str)
{
	int	op;
	int	red;
	int	green;
	int	blue;
	int	len;

	len = ft_strlen(str) - 1;
	op = 0;
	red = 0;
	green = 0;
	if (str[len] == '\n')
		len--;
	blue = hex_to_hex(str[len - 1], str[len]);
	len -= 2;
	if (len >= 3)
		green = hex_to_hex(str[len - 1], str[len]);
	len -= 2;
	if (len >= 3)
		red = hex_to_hex(str[len - 1], str[len]);
	len -= 2;
	if (len >= 3)
		op = hex_to_hex(str[len - 1], str[len]);
	return (create_trgb(op, red, green, blue));
}
