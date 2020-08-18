# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theinone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 11:51:41 by theinone          #+#    #+#              #
#    Updated: 2020/02/20 15:16:28 by theinone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   fractol
CC		=	gcc
CFLAGS  =  
SRC     =   ./sources/main.c
OBJ     =   main.o
MLX_LNK	= -L mlx/ -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a $(MLX_LNK) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	make re -C ./libft/
clean:
	rm -f $(OBJ)
	make clean -C ./libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/
re: fclean all

