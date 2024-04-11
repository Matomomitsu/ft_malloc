SRCS = ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

NAME = libft.a

CC = cc

LIB = ar -rcs

CFLAGS = -Wall -Werror -Wextra

HEADER = libft.h

OBJS = 		${SRCS:.c=.o}

OBJS_BONUS =	${SRCS_BONUS:.c=.o}

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -I . -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
				${LIB} ${NAME} ${OBJS}

bonus:	${NAME} ${OBJS_BONUS} ${HEADER}
			${LIB} ${NAME} ${OBJS_BONUS}

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
				rm -f ${NAME}

re:			fclean all

rebonus:	fclean	bonus

.PHONY:		all clean fclean re bonus rebonus
