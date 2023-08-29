/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:28:14 by nuferron          #+#    #+#             */
/*   Updated: 2023/08/14 13:11:00 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_BONUS_H
# define GNL_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

int		finding_enter(char *buffer);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*reading_buffer(int fd, char *storage);
char	*extract_line(char *storage);
char	*cleaning_storage(char *storage);
char	*get_next_line(int fd);

#endif
