CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = hangman
SRC = hangman.c utils.c game.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re