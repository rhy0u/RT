# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeaun-a <cmeaun-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 14:01:52 by cmeaun-a          #+#    #+#              #
#    Updated: 2017/11/03 02:39:16 by jcentaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

OBJDIR = obj/

SRCDIR = src/

HDRDIR = header/

SRC = main.c rgb.c ft_get_scene.c ft_rt.c sphere.c \
	ft_get_data.c ft_list.c ft_init_obj.c cylindre.c camera.c plane.c \
	vectors.c cone.c inter_obj.c light.c vector2.c rotation.c \
	cal_radian.c free_all.c gtk.c disk.c ft_cut.c ft_save.c ft_movecam.c \
	damier.c filters.c anti_aliasing.c movecam.c threads.c ft_init_obj2.c \
	vector3.c init.c \

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = libft/

LIBA = libft/libft.a

FLAGS = -Ofast -Wall -Werror -Wextra -Wuninitialized
FW = -framework SDL2

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\x1B[32mCompiling libft...\x1B[0m"
	@make -C $(LIBFT)
	@echo "\x1B[33mCreating binary $@ \x1B[0m"
	@gcc -o $(NAME) -I$(HDRDIR) $(LIBA) $(OBJ) $(FW) `pkg-config --libs --cflags gtk+-3.0`
	@echo "\x1B[31m\n\
RRRRRRRRRRRRRRRRR      TTTTTTTTTTTTTTTTTTTTTTT\n\
R::::::::::::::::R     T:::::::::::::::::::::T\n\
R::::::RRRRRR:::::R    T:::::::::::::::::::::T\n\
RR:::::R     R:::::R   T:::::TT:::::::TT:::::T\n\
  R::::R     R:::::R   TTTTTT  T:::::T  TTTTTT\n\
\x1B[93m  R::::R     R:::::R           T:::::T        \n\
  R::::RRRRRR:::::R            T:::::T        \n\
  R:::::::::::::RR             T:::::T        \n\
  R::::RRRRRR:::::R            T:::::T        \n\
  R::::R     R:::::R           T:::::T        \n\
\x1B[32m  R::::R     R:::::R           T:::::T        \n\
  R::::R     R:::::R           T:::::T        \n\
RR:::::R     R:::::R         TT:::::::TT      \n\
R::::::R     R:::::R         T:::::::::T      \n\
R::::::R     R:::::R         T:::::::::T      \n\
RRRRRRRR     RRRRRRR         TTTTTTTTTTT\x1B[0m"

$(OBJDIR)%.o:$(SRCDIR)%.c
	@echo "\x1B[34mCompiling $(<:src/%=%) \x1B[0m"
	@gcc $(FLAGS) -I$(HDRDIR) -I ./ -o $@ -c $< `pkg-config --cflags gtk+-3.0`

clean:
	@/bin/rm -f $(OBJ)
	@echo "\x1B[31mDeleting objects\x1B[0m"
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1B[31mDeleting binary\x1B[0m"
	@make -C $(LIBFT) fclean

re: fclean all
