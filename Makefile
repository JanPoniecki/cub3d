FLAGS = -g -Wall -Werror -Wextra
NAME = cub3d
LIB = ./mylibft/mylibft.a
OBJDIR = Obj/
MLX = mlxlibX/libmlx_Linux.a
SRC = main.c myjob.c start_utils.c calc.c debug.c ext_map.c moves.c\
	read_map.c check_map.c main.c dec_to_hex.c \
	write_textures.c delete_n.c interpolation.c ext_map_case.c \
	utils2.c write_to_ma.c put_image.c utils_3.c calc_for_text.c \
	overwrite.c tune_view.c fix_corners.c math_calc.c set_axis.c \
	calc_axis.c

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
