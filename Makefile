# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 15:54:22 by mgarnier          #+#    #+#              #
#    Updated: 2026/03/30 18:33:01 by mgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address #-O3 -march=native -flto -ffast-math 
DEPFLAGS	= -MMD -MP

# COLOR
GREEN   := \033[1;38;5;46m
RESET   := \033[0m

# DIR
DIR			= sources/
DIR_BONUS	= bonus/
OBJ_DIR		= objects/
MLX_DIR		= mlx/
UTILS		= $(DIR)utils/
PARSING		= $(DIR)parsing/
MOVING		= $(DIR)moving/
GRAPHIC		= $(DIR)graphic/
BONUS_PARS	= $(DIR_BONUS)parsing/
BONUS_GRAPH	= $(DIR_BONUS)graphic/
BONUS_MOV	= $(DIR_BONUS)moving/
BONUS_UTILS	= $(DIR_BONUS)utils/

# CUB3D
NAME		= cub3D
HEADER		= -Iincludes \
				-IGreat_Libft/Libft \
				-IGreat_Libft/ft_printf \
				-IGreat_Libft/GNL \
				-I$(MLX_DIR)includes

SRC			= $(DIR)main.c \
				$(UTILS)error_management.c \
				$(UTILS)free_memory.c \
				$(UTILS)events.c \
				$(UTILS)init_struct.c \
				$(UTILS)load_image.c \
				$(GRAPHIC)update_frame.c \
				$(GRAPHIC)set_background.c \
				$(GRAPHIC)draw_wall.c \
				$(GRAPHIC)minimap.c \
				$(PARSING)map_is_valid.c \
				$(PARSING)check_element.c \
				$(PARSING)parse_element.c \
				$(PARSING)check_map.c \
				$(PARSING)init_player_pos.c \
				$(PARSING)color_valid.c \
				$(MOVING)player_rotate.c \
				$(MOVING)player_move.c

SRC_BONUS	= $(DIR_BONUS)main_bonus.c \
				$(UTILS)error_management.c \
				$(UTILS)free_memory.c \
				$(UTILS)events.c \
				$(BONUS_UTILS)init_struct_bonus.c \
				$(BONUS_UTILS)load_image_bonus.c \
				$(BONUS_UTILS)set_mlx_struct.c \
				$(BONUS_UTILS)init_game_elem_pos.c \
				$(GRAPHIC)set_background.c \
				$(GRAPHIC)update_frame.c \
				$(GRAPHIC)minimap.c \
				$(BONUS_GRAPH)draw_wall_bonus.c \
				$(PARSING)check_element.c \
				$(PARSING)parse_element.c \
				$(PARSING)init_player_pos.c \
				$(PARSING)color_valid.c \
				$(BONUS_PARS)init_sprite_struct_bonus.c \
				$(BONUS_PARS)check_map_bonus.c \
				$(BONUS_PARS)map_is_valid_bonus.c \
				$(MOVING)player_rotate.c \
				$(BONUS_MOV)player_move_bonus.c \
				$(BONUS_MOV)door_bonus.c \
				$(BONUS_MOV)direction_bonus.c

OBJ			= $(SRC:$(DIR)%.c=$(OBJ_DIR)%.o)

OBJ_BONUS	= $(SRC_BONUS:$(DIR_BONUS)%.c=$(OBJ_DIR)%.o)

DEPS		= $(OBJ:.o=.d)

LIBFT		= ./Great_Libft/g_libft.a

all :		$(NAME)

$(NAME): $(MLX_DIR)libmlx.so $(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(HEADER) $(OBJ) -lm $(LIBFT) $(MLX_DIR)libmlx.so -lSDL2 -o $(NAME)
			@printf "${GREEN}\r[▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬] SUCCESS 100%%${RESET}\n"

bonus: $(MLX_DIR)libmlx.so $(OBJ_BONUS) $(LIBFT)
			@$(CC) $(CFLAGS) $(HEADER) $(OBJ_BONUS) -lm $(LIBFT) $(MLX_DIR)libmlx.so -lSDL2 -DBONUS -o $(NAME)
			@printf "${GREEN}\r[▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬] SUCCESS 100%%${RESET}\n"

$(LIBFT):
			@$(MAKE) -C Great_Libft --no-print-directory

TOTAL		:= $(words $(SRC))
COUNT		:= 0

$(OBJ_DIR)%.o: $(DIR)%.c
			@mkdir -p $(dir $@)
			@$(CC) -c $(CFLAGS) $(DEPFLAGS) $(HEADER) $< -o $@
			@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
			@PERCENT=$$(($(COUNT)*99/$(TOTAL))) ; \
			BAR=$$(($(COUNT)*39/$(TOTAL))) ; \
			if [ $$PERCENT -lt 33 ]; then \
				COLOR_CODE=196; \
			elif [ $$PERCENT -lt 66 ]; then \
				COLOR_CODE=208; \
			else \
				COLOR_CODE=226; \
			fi ; \
			printf "\033[38;5;%sm\r[" $$COLOR_CODE ; \
			i=1; while [ $$i -le $$BAR ]; do printf "▬"; i=$$((i+1)); done ; \
			while [ $$i -le 40 ]; do printf " "; i=$$((i+1)); done ; \
			printf "] LOADING %3d%%\033[0m" $$PERCENT

$(OBJ_DIR)%.o: $(DIR_BONUS)%.c
			@mkdir -p $(dir $@)
			@$(CC) -c $(CFLAGS) $(HEADER) $< -o $@
			@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
			@PERCENT=$$(($(COUNT)*99/$(TOTAL))) ; \
			BAR=$$(($(COUNT)*39/$(TOTAL))) ; \
			if [ $$PERCENT -lt 33 ]; then \
				COLOR_CODE=196; \
			elif [ $$PERCENT -lt 66 ]; then \
				COLOR_CODE=208; \
			else \
				COLOR_CODE=226; \
			fi ; \
			printf "\033[38;5;%sm\r[" $$COLOR_CODE ; \
			i=1; while [ $$i -le $$BAR ]; do printf "▬"; i=$$((i+1)); done ; \
			while [ $$i -le 40 ]; do printf " "; i=$$((i+1)); done ; \
			printf "] LOADING %3d%%\033[0m" $$PERCENT

$(MLX_DIR)libmlx.so:
			@git clone https://github.com/seekrs/MacroLibX.git -b v2.2.6 mlx
			@$(MAKE) -C mlx -j8 --no-print-directory

clean:
			@if ls $(OBJ) >/dev/null 2>&1; then \
			echo "${GREEN}====   $(NAME)   ==== : >>>OBJ CLEANED<<<${RESET}"; \
			fi
			@rm -f $(OBJ) $(DEPS)
			@rm -rf $(OBJ_DIR)
			@$(MAKE) -C Great_Libft clean --no-print-directory

fclean:		clean
			@if ls $(NAME) >/dev/null 2>&1; then \
			echo "${GREEN}====   $(NAME)   ==== : >>>ALL CLEANED<<<${RESET}"; \
			fi
			@rm -rf $(MLX_DIR)
			@rm -f $(NAME)
			@$(MAKE) -C Great_Libft fclean --no-print-directory

re:			fclean all

.PHONY:		all clean fclean re

-include $(DEPS)