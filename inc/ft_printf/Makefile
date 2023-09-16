# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 00:01:43 by nuferron          #+#    #+#              #
#    Updated: 2023/09/14 15:15:03 by nuferron         ###   ########.fr        #
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

SRCS =	ft_printf.c printf_char.c printf_string.c printf_num.c \
		printf_unsigned_num.c printf_pointers.c printf_hex_cap.c \
		printf_hex_min.c \

SRCS_BNS =	ft_printf_bonus.c printf_char_bonus.c printf_string_bonus.c \
				printf_num_bonus.c 	printf_unsigned_num_bonus.c \
				printf_pointers_bonus.c printf_hex_cap_bonus.c \
				printf_hex_min_bonus.c printf_percentage.c pf_bonus_padding.c \
				pf_bonus_flags.c pf_bonus_hexadecimal.c pf_bonus_precision.c \
				pf_bonus_sign.c len_functions.c \


OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJS_BNS = $(addprefix $(OBJDIR_BNS),$(SRCS_BNS:.c=.o))

OBJDIR = obj/
OBJDIR_BNS = obj_bonus/
SRCDIR = src/
SRCDIR_BNS = src_bonus/
NAME = libftprintf.a
HEADER = libftprintf.h
HEADER_LIBFT = libft/libft.h
CFLAGS = -Wall -Wextra -Werror
COLUMNS = $(shell tput cols)

all:		${NAME} make_libs

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}
		printf "${WHITE}FT_PRINTF: ${GREEN}Library compiled!${RESET}\n"

bonus:		make_libs do_bonus

do_bonus:	${OBJS_BNS}
		rm -rf obj/ ${NAME}
		cp libft/libft.a ${NAME}
		ar rcs ${NAME} ${OBJS_BNS}
		printf "${WHITE}FT_PRINTF: ${GREEN}Bonus compiled!${RESET}\n"
		touch do_bonus

make_libs:
		make -C libft bonus --no-print-directory

norm:
	make -C libft norm --no-print-directory
	printf "${WHITE}FT_PRINTF${RESET}\n"
	norminette $(addprefix ${SRCDIR},$(SRCS)) $(addprefix ${SRCDIR_BNS},$(SRCS_BNS)) ${HEADER} | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'

${OBJDIR}%.o:	${SRCDIR}%.c ${HEADER} | ${OBJDIR}
		@printf "${WHITE}FT_PRINTF:${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
		@cc $(CFLAGS) -I $(HEADER) -c $< -o $@
		@printf "\r%-${COLUMNS}s\r" ""

${OBJDIR}:
		mkdir -p $(dir $@)

${OBJDIR_BNS}%.o:	${SRCDIR_BNS}%.c ${HEADER} | ${OBJDIR_BNS}
		@printf "${WHITE}FT_PRINTF:${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
		@cc $(CFLAGS) -I $(HEADER) -c $< -o $@
		@printf "\r%-${COLUMNS}s\r" ""

${OBJDIR_BNS}:
		mkdir -p $(dir $@)

clean:
	if [ -d ${OBJDIR} ] || [ -d ${OBJDIR_BNS} ]; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS} ; \
		printf "${WHITE}FT_PRINTF: ${RED}Objects have been deleted${RESET}\n" ; \
	fi
	make -C libft clean --no-print-directory

fclean: 	clean
		if [ -e ${NAME} ] || [ -e do_bonus ] ; then \
			rm -rf ${NAME} do_bonus ; \
			printf "${WHITE}FT_PRINTF: ${RED}Static library has been deleted${RESET}\n" ; \
		else printf "${WHITE}FT_PRINTF: ${PURPLE}Already cleaned${RESET}\n" ; \
		fi
		make -C libft fclean --no-print-directory

re:	fclean all

re_bonus: fclean bonus

.SILENT: ${NAME} ${OBJDIR} clean fclean ${OBJDIR_BNS} do_bonus make_libs norm
.PHONY: all clean fclean re re_bonus bonus
