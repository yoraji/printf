NAME = libftprintf.a
CC = cc
FLAGS = -Werror -Wall -Wextra
ARCHIVE = ar rcs
SRC =	./ft_hexdecimal.c ./ft_putchar.c ./ft_unsigned.c \
		./ft_putstr.c ./ft_printf.c ./ft_putnbr.c ./ft_point.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
