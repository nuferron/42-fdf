/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:01:28 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/14 16:12:49 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	ft_abs(float num)
{
	if (num < 0)
		num = -num;
	return (num);
}

float	getting_float(float num)
{
	return (num - (int)num);
}

int	ft_round(float num)
{
	if (getting_float(num) >= 0.5)
		return ((int)num + 0.5);
	return ((int)num);
}
