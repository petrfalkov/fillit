# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichubare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/23 18:08:44 by ichubare          #+#    #+#              #
#    Updated: 2016/12/25 15:21:30 by mhlukhov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

SRC = 	arr_all.c \
        cut_arr.c \
        fig_to_norm.c \
        check.c \
        put_in.c \
        newhope.c \
        to_check.c \
		main.c \
		read_file.c \
		validate.c \
		ft_strrev.c \
		ft_lstpush_back.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcmp.c \
		ft_strnew.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_putendl.c \
		ft_memset.c \
		ft_memmove.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_putchar.c \
		ft_strncpy.c

OBJ = $(SRC:.c=.o)

HEADER = fillit.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
