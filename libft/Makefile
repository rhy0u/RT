# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmeaun-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 13:57:36 by cmeaun-a          #+#    #+#              #
#    Updated: 2017/02/14 17:45:07 by cmeaun-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS= ft_memset.c ft_strcat.c ft_strcmp.c ft_strcpy.c \
	  ft_strdup.c ft_strlen.c ft_strncmp.c ft_strncpy.c \
	  ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \
	  ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_strchr.c ft_strlcat.c \
	  ft_strncat.c ft_strrchr.c ft_tolower.c \
	  ft_toupper.c ft_isascii.c ft_atoi.c ft_putnbr.c\
	  ft_strnew.c ft_memalloc.c ft_memdel.c ft_strclr.c \
	  ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c \
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putstr.c \
	  ft_putendl.c ft_putchar.c ft_strstr.c ft_strnstr.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_itoa.c ft_lstnew.c ft_lstmap.c ft_lstiter.c ft_lstdelone.c \
	  ft_lstdel.c ft_lstadd.c ft_strjoinf.c ft_swap.c ft_range.c \
	  ft_foreach.c ft_strsubf.c get_next_line.c ft_isdigit_char.c

OBJ= $(SRCS:.c=.o)
CC = -Wall -Wextra -Werror -I .

.PHONY: clean
all: $(NAME)

$(NAME):
	gcc -c $(CC) $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
