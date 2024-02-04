# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:28:56 by ymomen            #+#    #+#              #
#    Updated: 2024/02/03 17:26:21 by ymomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =cc
CFLAGS =-Wall -Wextra -Werror -O3
MLX=-lmlx -framework OpenGL -framework AppKit
SRC =ft_strlen.c main.c math.c outils.c strncmp.c windo.c events.c ft_isdigit.c
OBJ =$(SRC:.c=.o)
NAME =fractol
HEADER =fractol.h
RM =rm -f

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
 
$(NAME) : $(OBJ)
	$(CC) $(MLX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY : clean all
