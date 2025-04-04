NAME	= pipex

CFLAGS	= -Wall -Werror -Wextra -g3

SRC	= pipex.c utils.c error.c

OBJ	= $(SRC:.c=.o)

HEADER 	= pipex.h

all	: $(NAME)

$(NAME)	: $(OBJ)
		cc $(CFLAGS) $(OBJ) libft.a -o $(NAME)

$(OBJ)	: $(SRC)
		$(MAKE) -C ./libft
		cp ./libft/libft.a .
		cc $(CFLAGS) -c $(SRC)

clean	:
		@rm -f $(OBJ)
		@$(MAKE) clean -C ./libft

fclean	: clean
		@$(MAKE) fclean -C ./libft
		@rm -f $(NAME) libft.a
		@echo "full clean done."

re	: fclean all
		@echo "full clean done. Make done too."
