NAME = cub3D

CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
INCLUDES = -I ./src -I ./MLX42/include -I ./MLX42/include/MLX42 -I ./libft

LIBFT_DIR = ./includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX42_DIR = ./MLX42
MLX42_BUILD = $(MLX42_DIR)/build
LIBMLX42 = $(MLX42_BUILD)/libmlx42.a
LIBS = $(LIBMLX42) -ldl -lglfw -pthread -lm
OBJ_DIR = objects
DEPS = ../includes/cub3d.h

SRC_DIR = src
PARSER_DIR = src/parsing
EXEC_DIR = src/exec
SAVING_DIR = $(EXEC_DIR)/load
INITIAL_PARS_DIR = $(PARSER_DIR)/initial_parser
RGB_DIR = $(PARSER_DIR)/rgb
MAP_DIR = $(PARSER_DIR)/map
CARDINAL_DIR = $(PARSER_DIR)/cardinal_points
UTILS_DIR = src/utils

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
		$(SAVING_DIR)/textures.c \

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX42) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(LIBS)
	@echo "linkingggg $(NAME) "

$(LIBMLX42):
	cmake -DDEBUG=1 $(MLX42_DIR) -B $(MLX42_BUILD)
	make -C $(MLX42_BUILD) -j4

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus --no-print-directory

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	rm -rf $(MLX42_BUILD)
	@echo "cleaningggg"

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	@echo "full cleaningggg"

SUPP = mlx.supp

val: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=$(SUPP) ./$(NAME) map.cub

run: all
	./$(NAME) map.cub

re: fclean all
