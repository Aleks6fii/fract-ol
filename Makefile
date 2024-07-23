# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afilippo <afilippo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 18:02:03 by afilippo          #+#    #+#              #
#    Updated: 2024/07/23 21:05:57 by afilippo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux
LIBS = -lmlx_Linux -lX11 -lXext
SRCS = events.c fractal_sketch.c init.c math_utils.c render.c string_utils.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
