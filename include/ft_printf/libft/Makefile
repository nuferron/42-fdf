# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 18:05:14 by nuferron          #+#    #+#              #
#    Updated: 2023/08/09 13:02:04 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRCSBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJS = ${SRCS:.c=.o}


HEADER = libft.h
NAME = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
OBJSBONUS = ${SRCSBONUS:.c=.o}

%.o: %.c $(HEADER)
	${CC} ${CFLAGS} -I libft.h -c $< -o ${<:.c=.o}


all: 		${NAME}

${NAME}:	${OBJS} 
		ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ${OBJSBONUS} ${HEADER}
			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
			@touch $@

norm:
	norminette ${SRCS} | grep -v "OK" | awk '{if($$2 == "Error!") \
	print "\033[1;31;m"$$1" "$$2; else print "\033[0;m"$$0}'

clean: 		
		${RM} ${OBJS} ${OBJSBONUS} 

fclean: 	clean
		${RM} ${NAME}
		${RM} bonus

re:		fclean all

.SILENT: norm
.PHONY: all clean fclean re
