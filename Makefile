# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 18:06:06 by ehattab           #+#    #+#              #
#    Updated: 2025/02/28 16:52:22 by ehattab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = parsing.c so_long.c utils.c checkmap.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./libft
# INCLUDES = -I/usr/include -Imlx -Iincludes
# MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11./so_long

all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft/
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./libft/libft.a
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	${MAKE} clean -C ./libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re