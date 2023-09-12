# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 20:02:39 by nuferron          #+#    #+#              #
#    Updated: 2023/09/12 18:11:41 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c xiaolin_alg.c maths.c colors.c errors.c print_utils.c \
		read_map.c free_file.c movements.c xiaolin_utils.c rotation.c

OBJS = ${SRCS:.c=.o}

NAME = fdf
HEADER = fdf.h macros.h
CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address
BIN = ./fdf
MLXHEADER = mlx.h
MLXFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	cc ${CFLAGS} -Imlx -c $< -o $@

all: make_libs ${NAME}

make_libs:
	@make -C include/ft_printf/ bonus --no-print-directory

${NAME}: ${SRCS} ${OBJS} Makefile
	@cp include/ft_printf/libftprintf.a .
	cc ${CFLAGS} ${OBJS} ${MLXFLAGS} libftprintf.a -o ${NAME}

norm:
	@make -C include/ft_printf norm --no-print-directory
	norminette ${SRCS} ${HEADER}| grep -v "OK" | awk '{if($$2 == "Error!") \
	print "\033[1;31;m"$$1" "$$2; else print "\033[0;m"$$0}'

leaks: ${OBJS}
	leaks -atExit -- ${BIN} ${MAP}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}
	@make -C include/ft_printf clean --no-print-directory

fclean:	clean
	rm -f ${NAME} ${BIN} libftprintf.a
	@make -C include/ft_printf fclean --no-print-directory
	clear

re:	fclean all

.SILENT: norm
.PHONY: all clean fclean re
