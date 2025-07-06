# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 17:32:59 by ktombola          #+#    #+#              #
#    Updated: 2025/06/29 17:50:29 by ktombola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := so_long

# Fontes
SRC     := main.c \
           map/parse.c map/parse1.c map/parse2.c \
           game/so_long_utils.c game/so_long_utils2.c \
           render/render_init.c render/render_img.c render/render_messages.c \

OBJ     := $(SRC:.c=.o)

CC      := cc
CFLAGS  := -Wall -Wextra -Werror

INCLUDES := -Iincludes -Ilibft -Imlx

LIBFT   := libft/libft.a
MLX     := mlx/libmlx.a
MLXFLAGS := -Lmlx -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C libft

$(MLX):
	make -C mlx

clean:
	rm -f $(OBJ)
	make clean -C libft
	make clean -C mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
