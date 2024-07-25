# FLAGS = -Wall -Wextra -Werror -g
FLAGS = -g 
NAME = cub3d
LIB = ./mylibft/mylibft.a
OBJDIR = Obj/
MLX = mlxlibX/libmlx_Linux.a
SRC = main.c myjob.c start_utils.c calc.c debug.c ext_map.c moves.c\
	fine_tune.c read_map.c check_map.c main.c dec_to_hex.c \
	write_textures.c delete_n.c interpolation.c

OBJ := $(SRC:%.c=$(OBJDIR)%.o)

all: $(NAME)
	@echo "Compilation completed."

$(NAME): mylibft/mylibft.a $(OBJ)
	@cc $(FLAGS) $^ -o $@ $(LIB) mlxlibX/libmlx_Linux.a -lXext -lX11 -lm

%.o: %.c
	@cc $(FLAGS) -Imlx_linux -O3 -c $< -o $@

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	@cc $(FLAGS) -c $< -o $@

mylibft/mylibft.a:
	@make -s -C mylibft

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@rm -rf out

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@echo "Cleared."
	@rm -rf out
	
re: fclean all

.PHONY: all, clean, fclean, re
