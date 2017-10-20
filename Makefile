# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 14:01:52 by cmeaun-a          #+#    #+#              #
#    Updated: 2017/10/20 04:25:26 by jcentaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

SRC = main.c rgb.c ft_get_scene.c ft_rt.c sphere.c \
	ft_get_data.c ft_list.c ft_init_obj.c cylindre.c camera.c plane.c \
	vectors.c cone.c inter_obj.c light.c vector2.c rotation.c \
	cal_radian.c free_all.c gtk.c disk.c ft_cut.c ft_save.c ft_movecam.c \
	damier.c filters.c anti_aliasing.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/

LIBA = libft/libft.a

FLAGS = -Ofast -Wall -Werror -Wextra -Wuninitialized
FW = -framework SDL2

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cc -o $(NAME) -I . $(LIBA) $(SRC) $(FW) `pkg-config --libs --cflags gtk+-3.0`

%.o: %.c
	gcc $(FLAGS) -I . -o $@ -c $< `pkg-config --cflags gtk+-3.0`

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
