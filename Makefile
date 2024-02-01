# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lj9 <lj9@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:28:56 by ymomen            #+#    #+#              #
#    Updated: 2024/02/01 20:51:48 by lj9              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INC=/usr/include
INCLIB=$(INC)/../lib
LFLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11
CC =cc
CFLAGS =-Wall -Wextra -Werror -lm -O3
MLX=-lmlx -framework OpenGL -framework AppKit
SRC =ft_strlen.c main.c math.c outils.c strncmp.c windo.c events.c ft_isdigit.c
OBJ =$(SRC:.c=.o)
NAME =fractol
HEADER = fractol.h
RM =rm -rf
# LFLAGS += -lbsd

# %.o : %.c $(HEADER)
#  	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS) 
# $(NAME) : $(OBJ)
# 	$(CC) $(MLX) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJ_B) 
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_BNS)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(NAME_BNS)

re: fclean all
.PHONY : clean all
