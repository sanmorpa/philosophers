SRCS =		main.c ft_info.c ./outils/ft_atoi.c ft_errors.c ft_threads.c ft_routine.c \
			ft_time.c ft_locks.c ./outils/ft_strlen.c ft_forks.c ft_alive.c

OBJS    =   ${SRCS:.c=.o}

NAME	= 	philo

CFLAGS	=	-Wall -Wextra -Werror

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