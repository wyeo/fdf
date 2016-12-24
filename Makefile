# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyeo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/24 03:10:34 by wyeo              #+#    #+#              #
#    Updated: 2015/06/09 22:36:56 by wyeo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK = -L./mlx -lmlx -framework OpenGL -framework AppKit
MLX = -I./mlx

CFILES = ./src/ft_main.c ./src/get_next_line.c ./src/ft_init.c \
		 ./src/ft_draw.c ./src/ft_octants_1_4.c ./src/ft_octants_5_8.c \
		 ./src/ft_ptr_func.c ./src/ft_list.c ./src/ft_list_2.c \
		 ./src/ft_check_maps.c ./src/ft_project.c \

OFILES = ft_main.o get_next_line.o ft_init.o ft_draw.o ft_octants_1_4.o \
		 ft_octants_5_8.o ft_ptr_func.o ft_list.o ft_list_2.o ft_check_maps.o \
		 ft_project.o

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): norme
	@$(CC) $(CFLAGS) -c $(CFILES) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBFT) $(LINK)

norme:
	@norminette $(CFILES)
	@norminette ./src/header.h

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
