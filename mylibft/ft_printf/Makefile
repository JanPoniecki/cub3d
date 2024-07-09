FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_percentcheck.c \
	ft_printf.c \
	ft_putchar.c \
	ft_puthex.c \
	ft_puthexup.c \
	ft_putnumber.c \
	ft_putunbr.c \
	ft_putstr.c \
	ft_void_pointer.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
