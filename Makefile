NAME =		libftprintf.a

SRC =		

SRC_BONUS =	

OBJ =		$(SRC:.c=.o)

OBJ_BONUS =	$(SRC_BONUS:.c=.o)

CC =		cc

CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

bonus:		.bonus

.bonus:		$(OBJ) $(OBJ_BONUS)
			ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)
			@touch .bonus

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ) $(OBJ_BONUS)

fclean:		clean
			rm -f $(NAME) .bonus

re:			fclean all

.PHONY:		all bonus clean fclean re