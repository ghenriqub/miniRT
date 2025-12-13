# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 20:39:24 by ghenriqu          #+#    #+#              #
#    Updated: 2025/12/13 21:16:43 by ghenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                               PROJECT NAME                                   #
# ============================================================================ #

NAME        = miniRT

# ============================================================================ #
#                            COMPILER & FLAGS                                  #
# ============================================================================ #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
LDFLAGS     = -lm

# ============================================================================ #
#                               MINILIBX                                       #
# ============================================================================ #

MLX_DIR     = minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext

# ============================================================================ #
#                              DIRECTORIES                                     #
# ============================================================================ #

SRC_DIR     = srcs
I_DIR       = includes
LIBFT_DIR   = libft

# ============================================================================ #
#                               INCLUDES                                       #
# ============================================================================ #

INCLUDES    = -I$(I_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# ============================================================================ #
#                               LIBRARIES                                      #
# ============================================================================ #

LIBFT       = $(LIBFT_DIR)/libft.a

# ============================================================================ #
#                               SOURCES                                        #
# ============================================================================ #

SRC         = $(SRC_DIR)/parser/0-main.c \
              $(SRC_DIR)/parser/1-get_scene.c \
              $(SRC_DIR)/parser/2-allocate.c \
              $(SRC_DIR)/parser/3-parser.c \
              $(SRC_DIR)/parser/3.1-parser_utils.c \
              $(SRC_DIR)/parser/3.2-parser_utils.c \
              $(SRC_DIR)/parser/3.3-parser_utils.c \
              $(SRC_DIR)/parser/3.4-parser_obj_utils.c \
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

# ============================================================================ #
#                               OBJECTS                                        #
# ============================================================================ #

OBJS        = $(SRC:.c=.o)

# ============================================================================ #
#                               COLORS                                         #
# ============================================================================ #

RESET       = \033[0m
BOLD        = \033[1m
GREEN       = \033[32m
YELLOW      = \033[33m
CYAN        = \033[36m
RED         = \033[31m

# ============================================================================ #
#                               RULES                                          #
# ============================================================================ #

.PHONY: all clean fclean re

all: $(NAME)

# Compile libft
$(LIBFT):
	@echo "$(CYAN)$(BOLD)[LIBFT]$(RESET) Compiling libft..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled$(RESET)"

# Compile MLX (only if needed)
$(MLX):
	@if [ ! -f $(MLX) ]; then \
		echo "$(CYAN)$(BOLD)[MLX]$(RESET) Compiling MiniLibX..."; \
		$(MAKE) --no-print-directory -C $(MLX_DIR) 2>&1 | grep -v "warning:" || true; \
		echo "$(GREEN)✓ MiniLibX compiled$(RESET)"; \
	fi

# Compile object files
%.o: %.c
	@echo "$(YELLOW)[CC]$(RESET) $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link final executable
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(CYAN)$(BOLD)[LINK]$(RESET) Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓✓✓ $(NAME) ready! ✓✓✓$(RESET)"

# Clean object files
clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files..."
	@rm -f $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(GREEN)✓ Clean complete$(RESET)"

# Full clean
fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) Removing executables..."
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean 2>/dev/null || true
	@echo "$(GREEN)✓ Full clean complete$(RESET)"

# Rebuild everything
re: fclean all

# ============================================================================ #
#                            END OF MAKEFILE                                   #
# ============================================================================ #
