# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 14:17:34 by hbutt             #+#    #+#              #
#    Updated: 2025/05/25 14:58:51 by hdelbecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAGENTA=\033[0;35m
CYAN=\033[0;36m
RESET=\033[0m

# Program file name
NAME	= cub3D

# Compiler and compilation flags
CC		= cc
CFLAGS	= -Werror -Wextra -Wall -g3

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# MinilibX
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx_Linux.a
MLX			= $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS	= -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

# Sources
SRC_PATH = ./src/
SRC		= main.c \
		check_args.c \
		parsing.c \
		init_data.c \
		init_data_2.c \
		debug.c \
		take_info_file.c \
		check_data.c \
		init_mlx.c \
		check_map_validity.c \
		controls.c \
		controls_checker.c \
		draw_raycasting.c \
		draw_map.c \
		draw_textures.c \
		check_map.c \
		utils_functions.c \
		utils_math.c \
		utils_draw.c \
		utils_raycasting.c \
		utils.c \
		utils_2.c \
		utils_file.c \
		take_rgb.c \
		take_paths.c
		  
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= ./objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Includes
INC			= -I ./includes/\
			  -I ./libft/\
			  -I $(MLX_PATH)

# Main rule 
all: $(OBJ_PATH) $(LIBFT) $(MLX) $(NAME)
	@printf "$(GREEN)✔ Build complete!\n"

# Objects directory rule
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(CYAN)Compiling: $<\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	@printf "$(YELLOW)🔧 Linking $(NAME)...\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX_FLAGS)
	@printf "$(GREEN)✔ Executable ready!\n"

# Libft rule
$(LIBFT):
	@printf "$(MAGENTA)📦 Building libft...\n"
	@make -sC $(LIBFT_PATH)

# MinilibX rule
$(MLX):
	@printf "$(MAGENTA)📦 Building MinilibX...\n"
	@make -sC $(MLX_PATH) 2>/dev/null 1>/dev/null

# Clean up build files rule
clean:
	@printf "$(RED)🧹 Cleaning object files...\n"
	@rm -rf $(OBJ_PATH)
	@make -sC $(LIBFT_PATH) clean
	@make -sC $(MLX_PATH) clean 2>/dev/null 1>/dev/null

# Remove program executable
fclean: clean
	@printf "$(RED)🗑️ Removing executable...\n"
	@rm -f $(NAME)
	@make -sC $(LIBFT_PATH) fclean
	@make -sC $(MLX_PATH) clean 2>/dev/null 1>/dev/null

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean
