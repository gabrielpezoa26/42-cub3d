NAME = cub3D

CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast -g

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

INCLUDES = -I ./includes -I $(MLX_DIR) -I $(LIBFT_DIR)

SRC_DIR = src
PARSER_DIR = $(SRC_DIR)/parsing
EXEC_DIR = $(SRC_DIR)/exec
SAVING_DIR = $(EXEC_DIR)/load
INITIAL_PARS_DIR = $(PARSER_DIR)/initial_parser
RGB_DIR = $(PARSER_DIR)/rgb
MAP_DIR = $(PARSER_DIR)/map
CARDINAL_DIR = $(PARSER_DIR)/cardinal_points
UTILS_DIR = $(SRC_DIR)/utils

SRC = $(SRC_DIR)/main.c \
      $(INITIAL_PARS_DIR)/parser.c \
      $(INITIAL_PARS_DIR)/parser_utils.c \
      $(INITIAL_PARS_DIR)/validate_file.c \
      $(INITIAL_PARS_DIR)/validate_file_utils.c \
      $(INITIAL_PARS_DIR)/init.c \
      $(CARDINAL_DIR)/rose_of_winds.c \
      $(RGB_DIR)/rgb.c \
      $(MAP_DIR)/map.c \
      $(MAP_DIR)/matrix.c \
      $(MAP_DIR)/matrix_utils.c \
      $(MAP_DIR)/flood_fill.c \
      $(MAP_DIR)/flood_fill_utils.c \
      $(UTILS_DIR)/cleanup.c \
      $(UTILS_DIR)/utils.c \
      $(SAVING_DIR)/textures.c

OBJ_DIR = objects
OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_DIR)/libmlx.a
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX_LIBS)
	@echo "$(NAME) created successfully!"

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -sC $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR) bonus

$(OBJ_DIR)/%.o: %.c includes/cub3d.h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MLX_DIR) clean
	@echo "Cleaning complete."

fclean: clean
	@echo "Performing full clean..."
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@echo "Full clean complete."

re: fclean all

SUPP = mlx.supp

# val: all
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=$(SUPP) ./$(NAME) map.cub

crica: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=$(SUPP) ./$(NAME) mapas/crica.cub

certo: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=$(SUPP) ./$(NAME) mapas/certo.cub

run: all
	./$(NAME) mapas/certo.cub

.PHONY: all clean fclean re val run