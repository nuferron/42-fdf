/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:07:08 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/14 16:10:50 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

int	file_type(char *path)
{
	int	prot;

	prot = ft_strlen(path);
	if (ft_strncmp(path + prot - 4, ".fdf\0", 4) != 0)
	{
		ft_printf("\033[1;31;mWrong type of file!\n\033[0;m");
		return (-1);
	}
	prot = open(path, O_RDONLY);
	if (prot == -1)
	{
		ft_printf("\033[1;31;mUnable to open \"%s\"\n\033[0;m", path);
		return (-1);
	}
	return (prot);
}

int	error_management(char *path)
{
	int	fd;

	fd = file_type(path);
	return (fd);
}
