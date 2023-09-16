# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 20:02:39 by nuferron          #+#    #+#              #
#    Updated: 2023/09/16 16:30:38 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

SRCS =	main.c xiaolin_alg.c maths.c colors.c errors.c print_utils.c \
		read_map.c free_file.c movements.c xiaolin_utils.c rotation.c

SRCDIR = src/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJDIR = obj/
NAME = fdf
HEADER = fdf.h macros.h
CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address
MLXHEADER = mlx.h
LIB = libftprintf.a
MLXFLAGS = -Linc/minilibx -lmlx -framework OpenGL -framework AppKit
COLUMNS = $(shell tput cols)

all: make_libs ${NAME}

make_libs:
	make -C inc/ft_printf bonus --no-print-directory

${NAME}: ${OBJS}
	cp inc/ft_printf/libftprintf.a .
	cc ${CFLAGS} ${OBJS} ${MLXFLAGS} libftprintf.a -o ${NAME}
	echo "\033[1;32;m./${NAME} successfully created \033[0;m"

norm:
	make -C inc/ft_printf norm --no-print-directory
	printf "${WHITE}FDF${RESET}\n"
	norminette $(addprefix ${SRCDIR},$(SRCS)) $(addprefix ${SRCDIR_BNS},$(SRCS_BNS)) ${HEADER} | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'

leaks: ${NAME}
	leaks -atExit -- ./${NAME} ${MAP}

${OBJDIR}%.o: ${SRCDIR}%.c ${HEADER}
	@printf "${WHITE}FDF: ${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
	@mkdir -p $(dir $@)
	@cc ${CFLAGS} -c $< -o $@
	@printf "\r%-${COLUMNS}s\r"

clean:
	if [ -d ${OBJDIR} ] ; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS} combination; \
		printf "${WHITE}FDF: ${RED}Objects have been deleted${RESET}\n"; \
	fi
	make -C inc/ft_printf clean --no-print-directory

fclean: 	clean
	if [ -e ${NAME} ] || [ -e ${LIB} ] ; then \
		rm -f ${NAME} ${LIB} do_bonus ; \
		printf "${WHITE}FDF: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else printf "${WHITE}FDF: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi
	make -C inc/ft_printf fclean --no-print-directory

re:	fclean all

.SILENT: norm make_libs clean fclean leaks ${NAME}
.PHONY: all clean fclean re leaks norm
