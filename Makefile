# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 16:42:34 by lgertrud          #+#    #+#              #
#    Updated: 2025/12/08 16:45:52 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

#compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror
LDFLAG = -lm

#directories
SRC_DIR = srcs
PARSER_DIR = $(SRC_DIR)/parser
RAY_DIR = $(SRC_DIR)/ray
VECTORS_DIR = $(SRC_DIR)/vectors
HIT_DIR = $(SRC_DIR)/object_intersection
I_DIR = includes
LIBFT_DIR = libft

#includes
INCLUDES = -I$(I_DIR) -I$(LIBFT_DIR)

#libraries
LIBFT = $(LIBFT_DIR)/libft.a

#sources
SRC = $(PARSER_DIR)/0-main.c \
			$(PARSER_DIR)/1-get_scene.c \
			$(PARSER_DIR)/2-allocate.c \
			$(PARSER_DIR)/3-parser.c \
			$(PARSER_DIR)/3.1-parser_utils.c \
			$(PARSER_DIR)/3.2-parser_utils.c \
			$(PARSER_DIR)/3.3-parser_utils.c \
			$(PARSER_DIR)/3.4-parser_obj_utils.c \
			$(PARSER_DIR)/support_functions.c \
			$(PARSER_DIR)/support_functions1.c \
		$(VECTORS_DIR)/vec3_add.c \
			$(VECTORS_DIR)/vec3_atovec3.c \
			$(VECTORS_DIR)/vec3_cmp.c \
			$(VECTORS_DIR)/vec3_cross.c \
			$(VECTORS_DIR)/vec3_dot.c \
			$(VECTORS_DIR)/vec3_len.c \
			$(VECTORS_DIR)/vec3_new.c \
			$(VECTORS_DIR)/vec3_normalize.c \
			$(VECTORS_DIR)/vec3_scale.c \
			$(VECTORS_DIR)/vec3_sub.c \
		$(RAY_DIR)/cam_data.c \
			$(RAY_DIR)/ray.c \
		$(HIT_DIR)/hit_cylinder.c \
			$(HIT_DIR)/hit_plane.c \
			$(HIT_DIR)/hit_sphere.c

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
