# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 21:19:36 by cmartine          #+#    #+#              #
#    Updated: 2019/03/02 00:49:35 by cmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# COMPILATION
CC =		clang
C_FLAGS =	-Werror -Wextra -Wall -g # -fsanitize=address -g3 # PENSER A ENLEVER LE G !!
ADD_FLAGS =

	# BINARY
NAME =		doom-nukem
DST =

	# DIRECTORIES
SRC_DIR =	src
OBJ_DIR =	obj
INC_DIR =	include\
			minilibx/\
			libft/

	# SOURCES
SRC =		draw_3d.c\
			draw_3d2.c\
			minimap.c\
			minimap2.c\
			hooks.c\
			draw_line.c\
			draw_line2.c\
			main.c\
			movement.c\
			movements2.c\
			raycasting.c\
			save_map.c\
			sprite.c\
			textures.c\
			delta_time.c\
			key_events.c\
			mouse_event.c\
			weapon.c\
			trump.c\
			init.c\
			game.c\
			player_events.c\
			sprite_events.c\
			creator_map.c\
			img_to_img.c\
			textures2.c\
			menu.c\
			settings_hook.c\
			difficulty_hook.c\

OBJ =		$(SRC:.c=.o)

	# PREFIXES
LIBFT =		-L libft/ -lft
MLIBX =		-L minilibx/ -lmlx -lm -framework OpenGL -framework AppKit

	# PATHS foreach
LIB_P =		$(addprefix -L, $(LIB_NAME)/)
SRC_P =		$(addprefix $(SRC_DIR)/, $(SRC))
OBJ_P =		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
INC_P =		$(foreach dir, $(INC_DIR), -I $(dir))

# *****************************************************************************

	# SPECIAL CHARS
LOG_CLEAR=		\033[2K
LOG_UP =		\033[A
LOG_NOCOLOR =	\033[0m
LOG_BOLD =		\033[1m
LOG_UNDERLINE =	\033[4m
LOG_BLINKING =	\033[5m
LOG_BLACK =		\033[1;30m
LOG_RED =		\033[1;31m
LOG_GREEN =		\033[1;32m
LOG_YELLOW =	\033[1;33m
LOG_BLUE =		\033[1;34m
LOG_VIOLET =	\033[1;35m
LOG_CYAN =		\033[1;36m
LOG_WHITE =		\033[1;37m

# *****************************************************************************

# RULES

all:	libft_comp mlibx_comp $(OBJ_DIR) $(NAME) #norme

$(NAME): $(OBJ_P)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(C_FLAGS) $(ADD_FLAGS) $(MLIBX) $(LIBFT) $^ -o $@ $(INC_P)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR) compiled........... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

re:		fclean all

libft_comp:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build libft$(LOG_NOCOLOR)"
	@make all -C libft/
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)libft$(LOG_NOCOLOR) compiled.......... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

mlibx_comp:
	@echo -e "$(LOG_CLEAR) $(LOG_BLUE)build minilibx$(LOG_NOCOLOR)"
	@make all -C minilibx/
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)minilibx$(LOG_NOCOLOR) compiled.......... $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(C_FLAGS) $(ADD_FLAGS) -c $^ -o $@  $(INC_P)

$(OBJ_DIR):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJ_DIR) 2> /dev/null || true

.PHONY: clean fclean

clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJ_DIR)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean minilibx$(LOG_NOCOLOR)"
	@make clean -C minilibx/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean libft$(LOG_NOCOLOR)"
	@make clean -C libft/

fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean minilibx$(LOG_NOCOLOR)"
	@make clean -C minilibx/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean libft$(LOG_NOCOLOR)"
	@make fclean -C libft/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJ_DIR)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)

# NORME
norme:
	norminette $(SRC_DIR)
	norminette $(INC_DIR)*.h

