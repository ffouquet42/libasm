ASM_SRCS	=	srcs/asm/ft_strlen.s	\
				srcs/asm/ft_strcpy.s	\
				srcs/asm/ft_strcmp.s	\
				srcs/asm/ft_write.s		\
				srcs/asm/ft_read.s		\
				srcs/asm/ft_strdup.s	\

ASM_OBJS	=	$(ASM_SRCS:.s=.o)

TEST_SRCS		=	srcs/libasm.c		\

TEST_OBJS		=	$(TEST_SRCS:.c=.o)

CC			=	cc
NASM		=	nasm
AR 			=	ar
ARFLAGS		=	rcs
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror
NASM_FLAGS	=	-f elf64

NAME		=	libasm.a
TESTER		=	tester

all:		$(NAME)

$(NAME): $(ASM_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(ASM_OBJS)

$(TESTER):	$(NAME) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(NAME) -o $(TESTER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(NASM) $(NASM_FLAGS) $< -o $@

clean:
	$(RM) $(ASM_OBJS) $(TEST_OBJS)

fclean:		clean
	$(RM) $(NAME) $(TESTER)
	@rm -rf srcs/testing/ft_write_testing.txt

re:			fclean all

.PHONY:		all clean fclean re