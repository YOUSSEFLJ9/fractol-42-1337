# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lj9 <lj9@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:28:56 by ymomen            #+#    #+#              #
#    Updated: 2024/01/30 19:59:21 by lj9              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INC=/usr/include
INCLIB=$(INC)/../lib
LFLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11
CC =cc
CFLAGS =   -O3
MLX=-lmlx -framework OpenGL -framework AppKit
SRC =ft_strlen.c main.c math.c outils.c strncmp.c windo.c events.c ft_isdigit.c
OBJ =$(SRC:.c=.o)
SRC_BNS = ft_split.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strncmp.c pipex_otuls.c env_path.c ft_strtok.c bonus/main_bonus.c bonus/pipex_otuls_bonus.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c
OBJ_B = $(SRC_BNS:.c=.o)
NAME =fractol
NAME_BNS =pipex_bonus
HEADER = fractol.h
RM =rm -rf
LFLAGS += -lbsd

# %.o : %.c $(HEADER)
# 	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS) 
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