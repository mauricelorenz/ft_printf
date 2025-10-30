NAME =		libft.a

SRC =		ft_putchar_count.c \
			ft_puthex_count.c \
			ft_putnbr_count.c \
			ft_putptr_count.c \
			ft_putstr_count.c \
			ft_putunbr_count.c

OBJ =		$(SRC:.c=.o)

CC =		cc

CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re