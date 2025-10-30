NAME =		libftprintf.a

LIBFT =		./libft/libft.a

SRC =		ft_printf.c

OBJ =		$(SRC:.c=.o)

CC =		cc

CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -C ./libft
			cp $(LIBFT) $(NAME)
			ar rcs $(NAME) $(OBJ)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)
			$(MAKE) -C ./libft clean

fclean:		clean
			rm -f $(NAME)
			$(MAKE) -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re