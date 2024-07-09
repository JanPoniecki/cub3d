FLAGS = -Wall -Wextra -Werror
NAME = mylibft.a

all: $(NAME)

$(NAME): 
	make -C libft
	make -C ft_printf
	make -C get_next_line
	ar rcs $(NAME) libft/*.o ft_printf/*.o get_next_line/*.o

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@make clean -C get_next_line

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@make fclean -C get_next_line
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

