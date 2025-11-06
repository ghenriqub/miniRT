# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 16:42:34 by lgertrud          #+#    #+#              #
#    Updated: 2025/11/06 16:57:53 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

#compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror

#directories
SRC_DIR = src
PARSER_DIR = srcs/parser
I_DIR = includes
LIBFT_DIR = libft

#includes
INCLUDES = -I$(I_DIR) -I$(LIBFT_DIR)

#libraries
LIBFT = $(LIBFT_DIR)/libft.a

#sources
SRC = $(PARSER_DIR)/0-main.c \
			$(PARSER_DIR)/support_functions.c

#objects
OBJS = $(SRC:.c=.o)

# Colors
YELLOW = \e[93m
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;34m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(INTRO)
	@echo "$(YELLOW)[LOADING...]$(RESET)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(END)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(LDFLAG) -o $(NAME)

%.o: %.c
	@echo "$(YELLOW)[.o]$(RESET)Compiling $<..."
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files..."
	@rm -f $(OBJS) $(OBJSB)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean:
	@echo "$(RED)[FCLEAN]$(RESET) Removing all generated files..."
	@rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJSB)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all