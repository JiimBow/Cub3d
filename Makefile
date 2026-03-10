# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 15:54:22 by mgarnier          #+#    #+#              #
#    Updated: 2026/03/10 11:43:30 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

# COLOR
GREEN   := \033[1;38;5;46m
RESET   := \033[0m

# DIR
DIR			= sources/
OBJ_DIR		= objects/
MLX_DIR		= mlx/

# MINISHELL
NAME		= cub3D
HEADER		= -Iincludes \
				-IGreat_Libft/Libft \
				-IGreat_Libft/ft_printf \
				-IGreat_Libft/GNL \
				-I$(MLX_DIR)includes

SRC			= $(DIR)main.c

OBJ			= $(SRC:%.c=$(OBJ_DIR)%.o)

LIBFT		= ./Great_Libft/g_libft.a

all :		$(NAME)

$(NAME): $(MLX_DIR)libmlx.so $(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(HEADER) $(OBJ) $(LIBFT) $(MLX_DIR)libmlx.so -lSDL2 -o $(NAME)
			@printf "${GREEN}\r[▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬] SUCCESS 100%%${RESET}\n"

$(LIBFT):
			@$(MAKE) -C Great_Libft --no-print-directory

TOTAL		:= $(words $(SRC))
COUNT		:= 0

$(OBJ_DIR)%.o: %.c
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
			@git clone https://github.com/seekrs/MacroLibX.git -b v2.2.2 mlx
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
