FLAGS = -g -Wall -Werror -Wextra
NAME = cub3d
LIB = ./mylibft/mylibft.a
OBJDIR = Obj/
MLX = mlxlibX/libmlx_Linux.a
SRC = meat/main.c \
	meat/myjob.c \
	meat/start_utils.c \
	meat/calc.c \
	meat/debug.c \
	meat/ext_map.c \
	meat/moves.c \
	meat/read_map.c \
	meat/check_map.c \
	meat/main.c \
	meat/dec_to_hex.c \
	meat/write_textures.c \
	meat/delete_n.c \
	meat/interpolation.c \
	meat/ext_map_case.c \
	meat/utils2.c \
	meat/write_to_ma.c \
	meat/put_image.c \
	meat/utils_3.c \
	meat/calc_for_text.c \
	meat/overwrite.c \
	meat/tune_view.c \
	meat/fix_corners.c \
	meat/math_calc.c \
	meat/set_axis.c \
	meat/calc_axis.c

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
