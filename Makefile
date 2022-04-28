SRCS =		main.c info.c ./outils/ft_atoi.c errors.c threads.c routine.c \
			time.c locks.c ./outils/ft_strlen.c forks.c alive.c ./outils/check.c

OBJS    =   ${SRCS:.c=.o}

NAME	= 	philo

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

CC		=	gcc

RM		=	rm -f

LTHREAD = -lpthread

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LTHREAD} 

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclean re