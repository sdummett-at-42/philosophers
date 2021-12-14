# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:05:51 by sdummett          #+#    #+#              #
#    Updated: 2021/12/13 14:03:18 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -c -pthread
NAME	= philo
SRC		= main.c ft_strlen.c ft_strerror.c
OBJ		= $(SRC:.c=.o)
INCLUDES	= $(wildcard include/*.h)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) -Iinclude $(CFLAGS) -o $@ $<

bonus: NEANT

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
