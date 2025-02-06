# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbutt <hbutt@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 14:17:34 by hbutt             #+#    #+#              #
#    Updated: 2025/02/06 15:14:22 by hbutt            ###   ########.fr        #
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

# Sources
SRC_PATH = ./src/
SRC		= main.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= ./objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

# Includes
INC			= -I ./includes/\
			  -I ./libft/\

# Main rule
all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)
	@echo "$(GREEN)✔ Build complete!$(RESET)"

# Objects directory rule
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

# Objects rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(CYAN)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Project file rule
$(NAME): $(OBJS)
	@echo "$(YELLOW)🔧 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) 
	@echo "$(GREEN)✔ Executable ready!$(RESET)"

# Libft rule
$(LIBFT):
	@echo "$(MAGENTA)📦 Building libft...$(RESET)"
	@make -sC $(LIBFT_PATH)

# Clean up build files rule
clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_PATH)
	@make -sC $(LIBFT_PATH) clean

# Remove program executable
fclean: clean
	@echo "$(RED)🗑️ Removing executable...$(RESET)"
	@rm -f $(NAME)
	@make -sC $(LIBFT_PATH) fclean

# Clean + remove executable
re: fclean all

.PHONY: all re clean fclean 
