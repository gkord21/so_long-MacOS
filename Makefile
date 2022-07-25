# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkord <gkord@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 15:56:34 by gkord             #+#    #+#              #
#    Updated: 2022/05/27 18:28:26 by gkord            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	so_long

SRC		=	main.c\
			read_map.c\
			error_exit.c\
			start_game.c\
			gnl/get_next_line_utils.c\
			gnl/get_next_line.c\
			check_map.c\
			check_map2.c\
			render.c\
			move.c\
			xpm_init.c\
			add_enemy.c\
			animations.c\
			enemy_behavior.c\
			player_death.c\
			print_xpm.c

OBJ		=	$(SRC:.c=.o)
HDR		= 	so_long.h
LFT		=	Libft/libft.a
MLX		=	minilibx/libmlx.a
CC		=	gcc
FLAGS 	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
RM		=	rm -f

all:		 $(LFT) $(MLX) $(NAME)

$(LFT):
			@make -s -C libft

$(MLX):
			@make -s -C minilibx

$(NAME):	$(HDRS) $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFT) $(MLX)

bonus:		all

clean:
		make -s $@ -C libft
		make clean -C minilibx
		$(RM) $(OBJ) $(BOBJ)

fclean: clean
		make -s $@ -C libft
		make clean -C minilibx
		$(RM) $(NAME) $(NAME_B)

re:      fclean all

.PHONY: all clean fclean bonus re