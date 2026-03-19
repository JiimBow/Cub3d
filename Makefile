# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgarnier <mgarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 15:54:22 by mgarnier          #+#    #+#              #
#    Updated: 2026/03/19 15:05:54 by mgarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -MMD -MP -O3 -march=native -flto -ffast-math

# COLOR
GREEN   := \033[1;38;5;46m
RESET   := \033[0m

# DIR
DIR			= sources/
OBJ_DIR		= objects/
MLX_DIR		= mlx/
UTILS		= $(DIR)utils/
PARSING		= $(DIR)parsing/
MOVING		= $(DIR)moving/

# MINISHELL
NAME		= cub3D
HEADER		= -Iincludes \
				-IGreat_Libft/Libft \
				-IGreat_Libft/ft_printf \
				-IGreat_Libft/GNL \
				-I$(MLX_DIR)includes

SRC			= $(DIR)main.c \
				$(UTILS)error_management.c \
				$(UTILS)free_memory.c \
				$(UTILS)fps_calculator.c \
				$(UTILS)events.c \
				$(UTILS)set_background.c \
				$(UTILS)init_struct.c \
				$(UTILS)draw_wall.c \
				$(PARSING)map_is_valid.c \
				$(PARSING)check_element.c \
				$(PARSING)parse_element.c \
				$(PARSING)check_map.c \
				$(MOVING)player_move.c \
				$(MOVING)player_rotate.c

OBJ			= $(SRC:$(DIR)%.c=$(OBJ_DIR)%.o)

DEPS		= $(SRC:$(DIR)%.c=$(OBJ_DIR)%.d)

LIBFT		= ./Great_Libft/g_libft.a

all :		$(NAME)

$(NAME): $(MLX_DIR)libmlx.so $(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(HEADER) $(OBJ) -lm $(LIBFT) $(MLX_DIR)libmlx.so -lSDL2 -o $(NAME)
			@printf "${GREEN}\r[▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬] SUCCESS 100%%${RESET}\n"

$(LIBFT):
			@$(MAKE) -C Great_Libft --no-print-directory

TOTAL		:= $(words $(SRC))
COUNT		:= 0

$(OBJ_DIR)%.o: $(DIR)%.c
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
			@rm -f $(OBJ)
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