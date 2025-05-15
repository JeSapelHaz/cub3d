# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 14:17:34 by hbutt             #+#    #+#              #
#    Updated: 2025/05/15 11:33:06 by hbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ANSI Colors
ESC     = \033
RED     = $(ESC)[0;31m
GREEN   = $(ESC)[0;32m
YELLOW  = $(ESC)[0;33m
BLUE    = $(ESC)[0;34m
MAGENTA = $(ESC)[0;35m
CYAN    = $(ESC)[0;36m
RESET   = $(ESC)[0m

NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3

# Libft
LIBFT_PATH  = libft/
LIBFT_NAME  = libft.a
LIBFT       = $(LIBFT_PATH)$(LIBFT_NAME)

# MinilibX
MLX_PATH    = minilibx-linux/
MLX_NAME    = libmlx_Linux.a
MLX         = $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS   = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

# Sources
SRC_PATH = ./src/
SRC = main.c check_args.c parsing.c utils.c init_data.c debug.c \
      take_info_file.c check_data.c utils_functions.c utils_math.c \
      init_mlx.c check_map_validity.c controls.c draw_raycasting.c \
      draw_map.c draw_textures.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH = ./objects/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

# Includes
INC = -I ./includes/ -I ./libft/ -I $(MLX_PATH)

# Build rules

all: $(OBJ_PATH) $(LIBFT) $(MLX) $(NAME)
	@echo -e "$(GREEN)✔ Build complete!$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -e "$(CYAN)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	@echo -e "$(YELLOW)🔧 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX_FLAGS)
	@echo -e "$(GREEN)✔ Executable ready!$(RESET)"

$(LIBFT):
	@echo -e "$(MAGENTA)📦 Building libft...$(RESET)"
	@make -sC $(LIBFT_PATH)

$(MLX):
	@echo -e "$(MAGENTA)📦 Building MinilibX...$(RESET)"
	@make -sC $(MLX_PATH) >/dev/null 2>&1

clean:
	@echo -e "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_PATH)
	@make -sC $(LIBFT_PATH) clean
	@make -sC $(MLX_PATH) clean >/dev/null 2>&1

fclean: clean
	@echo -e "$(RED)🗑️  Removing executable...$(RESET)"
	@rm -f $(NAME)
	@make -sC $(LIBFT_PATH) fclean
	@make -sC $(MLX_PATH) clean >/dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
