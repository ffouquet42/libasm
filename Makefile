SRCS		=	srcs/libasm.c			\

OBJS		=	$(SRCS:.c=.o) #.s

CC			=	cc

RM			=	rm -f

#CFLAGS		=	-Wall -Wextra -Werror

NAME		=	prog

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re