# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 20:39:24 by ghenriqu          #+#    #+#              #
#    Updated: 2025/12/17 14:17:44 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = miniRT
NAME_BONUS	= miniRT_bonus

# Compiler
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
LDFLAGS     = -lm

# Directories
SRC_DIR     = srcs
I_DIR       = includes
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux
SRC_DIR_B    = srcs_bonus

# Libraries
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext

# Includes
INCLUDES    = -I$(I_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Sources
SRC         =	$(SRC_DIR)/parser/0-main.c \
					$(SRC_DIR)/parser/1-get_scene.c \
					$(SRC_DIR)/parser/2-allocate.c \
					$(SRC_DIR)/parser/3-parser.c \
					$(SRC_DIR)/parser/3.1-parser_utils.c \
					$(SRC_DIR)/parser/3.2-parser_utils.c \
					$(SRC_DIR)/parser/3.3-parser_utils.c \
					$(SRC_DIR)/parser/3.4-parser_obj_utils.c \
					$(SRC_DIR)/parser/3.5-parser_l.c \
					$(SRC_DIR)/parser/support_functions.c \
					$(SRC_DIR)/parser/support_functions1.c \
				$(SRC_DIR)/vectors/vec3_add.c \
					$(SRC_DIR)/vectors/vec3_atovec3.c \
					$(SRC_DIR)/vectors/vec3_cmp.c \
					$(SRC_DIR)/vectors/vec3_cross.c \
					$(SRC_DIR)/vectors/vec3_cos.c \
					$(SRC_DIR)/vectors/vec3_dot.c \
					$(SRC_DIR)/vectors/vec3_len.c \
					$(SRC_DIR)/vectors/vec3_new.c \
					$(SRC_DIR)/vectors/vec3_normalize.c \
					$(SRC_DIR)/vectors/vec3_scale.c \
					$(SRC_DIR)/vectors/vec3_sub.c \
				$(SRC_DIR)/ray/cam_data.c \
					$(SRC_DIR)/ray/ray.c \
				$(SRC_DIR)/object_intersection/hit_objects.c \
					$(SRC_DIR)/object_intersection/hit_cylinder.c \
					$(SRC_DIR)/object_intersection/hit_plane.c \
					$(SRC_DIR)/object_intersection/hit_sphere.c \
				$(SRC_DIR)/lighting/ambient_light.c \
					$(SRC_DIR)/lighting/diffuse.c \
					$(SRC_DIR)/lighting/shade_hit.c \
					$(SRC_DIR)/lighting/support_lighting.c \
				$(SRC_DIR)/render/render.c \
					$(SRC_DIR)/render/normal.c \
				$(SRC_DIR)/graphics/events.c \
					$(SRC_DIR)/graphics/minilibx_setup.c

SRC_BONUS	=	$(SRC_DIR_B)/parser_bonus/0-main_bonus.c \
					$(SRC_DIR_B)/parser_bonus/1-get_scene_bonus.c \
					$(SRC_DIR_B)/parser_bonus/2-allocate_bonus.c \
					$(SRC_DIR_B)/parser_bonus/3-parser_bonus.c \
					$(SRC_DIR_B)/parser_bonus/3.1-parser_utils_bonus.c \
					$(SRC_DIR_B)/parser_bonus/3.2-parser_utils_bonus.c \
					$(SRC_DIR_B)/parser_bonus/3.3-parser_utils_bonus.c \
					$(SRC_DIR_B)/parser_bonus/3.4-parser_obj_utils_bonus.c \
					$(SRC_DIR_B)/parser_bonus/3.5-parser_l_bonus.c \
					$(SRC_DIR_B)/parser_bonus/support_functions_bonus.c \
					$(SRC_DIR_B)/parser_bonus/support_functions1_bonus.c \
				$(SRC_DIR_B)/vectors_bonus/vec3_add_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_atovec3_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_cmp_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_cross_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_cos_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_dot_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_len_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_new_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_normalize_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_scale_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_sub_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_rgb_scale_bonus.c \
					$(SRC_DIR_B)/vectors_bonus/vec3_reflect_bonus.c \
				$(SRC_DIR_B)/ray_bonus/cam_data_bonus.c \
					$(SRC_DIR_B)/ray_bonus/ray_bonus.c \
				$(SRC_DIR_B)/object_intersection_bonus/hit_objects_bonus.c \
					$(SRC_DIR_B)/object_intersection_bonus/hit_cylinder_bonus.c \
					$(SRC_DIR_B)/object_intersection_bonus/hit_plane_bonus.c \
					$(SRC_DIR_B)/object_intersection_bonus/hit_sphere_bonus.c \
				$(SRC_DIR_B)/lighting_bonus/ambient_light_bonus.c \
					$(SRC_DIR_B)/lighting_bonus/diffuse_bonus.c \
					$(SRC_DIR_B)/lighting_bonus/shade_hit_bonus.c \
					$(SRC_DIR_B)/lighting_bonus/support_lighting_bonus.c \
				$(SRC_DIR_B)/render_bonus/render_bonus.c \
					$(SRC_DIR_B)/render_bonus/normal_bonus.c \
				$(SRC_DIR_B)/graphics_bonus/events_bonus.c \
					$(SRC_DIR_B)/graphics_bonus/minilibx_setup_bonus.c

OBJS        = $(SRC:.c=.o)
OBJS_BONUS        = $(SRC_BONUS:.c=.o)

# Colors
GREEN       = \033[32m
YELLOW      = \033[33m
RED         = \033[31m
RESET       = \033[0m

# Rules
# Rules
.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "$(YELLOW)Compiled:$(RESET) $(MLX_DIR) $<"
	@$(MAKE) -s -C $(MLX_DIR) --no-print-directory > /dev/null 2>&1 || true
	@echo "$(GREEN)✓ MLX ready!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)Compiled:$(RESET) $<"

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@if [ -f $(NAME_BONUS) ]; then \
		rm -f $(NAME_BONUS); \
	fi
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) ready!$(RESET)"

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
	fi
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) $(LDFLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)✓ $(NAME_BONUS) ready!$(RESET)"


clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(RED)Cleaned object files$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory 2>/dev/null || true
	@echo "$(RED)Cleaned executables$(RESET)"

re: fclean all
