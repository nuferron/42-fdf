SRCS =main.c	
OBJS = ${SRCS:.c=.o}

NAME = fdf
HEADER = fdf.h
CFLAGS = -Wall -Wextra -Werror
BIN = fdf
MLXHEADER = mlx.h
MLXFLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	cc ${CFLAGS} -Imlx -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	cc ${OBJS} ${MLXFLAGS} -o ${NAME}

norm:
	make -C inc/ft_printf norm --no-print-directory
	norminette ${SRCS} ${SRCS_BNS} | grep -v "OK" | awk '{if($$2 == "Error!") \
	print "\033[1;31;m"$$1" "$$2; else print "\033[0;m"$$0}'

clean:
	@rm -f ${OBJS} $ ${OBJS_BONUS}

fclean:	clean
	@rm -f ${NAME}
	rm -f ${BIN}

re:	fclean all

.SILENT: norm
.PHONY: all clean fclean re
