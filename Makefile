# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jazarago <jazarago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 10:46:06 by jazarago          #+#    #+#              #
#    Updated: 2024/03/14 15:15:53 by jazarago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

INCLUDE 	= so_long.h

LIBFT 		= Libft

CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra -Imlx

RM 			= rm -rf

MLX_FLAGS 	= -lmlx -framework OpenGL -framework AppKit

SRC 		= ft_error.c the_parse.c mapchecks.c mapchecks2.c handle_closings.c \
				map_things.c char_moves.c main.c ft_move.c ft_morethanonepe.c \
					checks_main.c mapchecks3.c ft_freemap.c

OBJ 		=$(SRC:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJ)
			@MAKE -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJ) -fsanitize=address $(MLX_FLAGS) Libft/Libft.a -o $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
			
clean:
			@$(RM) $(OBJ)
			@make clean -C $(LIBFT)
			
fclean:		clean
			@$(RM) $(NAME)

re: 		all clean

.PHONY:		all clean fclean re