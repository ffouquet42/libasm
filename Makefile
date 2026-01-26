C_SRCS		=	srcs/libasm.c			\

ASM_SRCS	=	srcs/asm/ft_strlen.s	\
				srcs/asm/ft_strcpy.s	\
				srcs/asm/ft_strcmp.s	\
				srcs/asm/ft_write.s		\
				srcs/asm/ft_read.s		\
				srcs/asm/ft_strdup.s	\

C_OBJS		=	$(C_SRCS:.c=.o)
ASM_OBJS	=	$(ASM_SRCS:.s=.o)

OBJS		=	$(C_OBJS) $(ASM_OBJS)

CC			=	cc
NASM		=	nasm
RM			=	rm -f

#CFLAGS		=	-Wall -Wextra -Werror
#asm flag

NAME		=	prog #libasm.a

# creer dossier testing au make et delete fichiers dedans au clean

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compilation C
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation ASM (64-bit, format ELF)
%.o: %.s
	$(NASM) -f elf64 $< -o $@

# Compilation ASM (MACOS)
#%.o: %.s
#	$(NASM) -f macho64 $< -o $@


clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)
	@rm -rf srcs/testing/ft_write_testing.txt
# var

re:			fclean $(NAME)

.PHONY:		all clean fclean re