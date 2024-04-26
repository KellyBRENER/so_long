# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbrener- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 14:58:49 by kbrener-          #+#    #+#              #
#    Updated: 2024/04/26 14:40:13 by kbrener-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME	= so_long

# Compiler options
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

# Libft
LIBFT_NAME = libft.a
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# MinilibX
MLX_NAME = libmlx.a
MLX_PATH = ./mlx/
MLX = $(MLX_PATH)$(MLX_NAME)
#MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# so_long files
SRC		= 	src/so_long.c \
			src/check_map.c \
			src/check_map_utils.c \
			src/init.c \
			src/clean_error.c \
			src/print.c\
			src/keypress.c \

OBJ		= $(SRC:.c=.o)

# Includes
INC = 	-I ./mlx/\
			-I ./libft/\

# Colors
RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m
BLUE = \033[94m

all : $(MLX) $(LIBFT) $(NAME)

# Compiling Libft and Mlx
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -sC $(LIBFT_PATH)
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"

$(MLX):
	@echo "$(BOLD)$(RED)🛠️      Compiling MiniLibX      🛠️$(RESET)"
	@echo "\n"
	@make all -sC $(MLX_PATH)
	@echo "\n"
	@echo "$(BOLD)$(GREEN)😎     MiniLibX Compiled    😎$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------$(RESET)"
	@echo "\n"

# Compiling so_long
$(NAME): $(OBJ)
	@echo "$(BOLD)$(RED)🛠️      Compiling so_long    🛠️$(RESET)"
	@echo "\n"
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm -lz -o $(NAME) -g
	@echo "$(BOLD)$(GREEN)✅✅      so_long fully compiled, ready to use       ✅✅$(RESET)"
	@echo "\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o so_long's files   🌀$(RESET)"
	@make clean -sC $(MLX_PATH)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o MiniLibX's files  🌀$(RESET)"

fclean: clean
	@make fclean -sC libft/
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned so_long exec       🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
