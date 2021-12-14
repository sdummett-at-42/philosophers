# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:05:51 by sdummett          #+#    #+#              #
#    Updated: 2021/12/14 20:49:57 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -c -pthread
NAME		= philo

INCLUDES	= $(wildcard include/*.h)

SRCS_DIR	= srcs/
OBJS_DIR	= objs/

SRCS_FILES	= main.c ft_strlen.c ft_strerror.c is_number.c check_args.c
SRCS 		= $(addprefix ${SRCS_DIR}, ${SRC_FILES})

OBJS_FILES	= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix ${OBJS_DIR}, ${OBJS_FILES})

RMRF		= rm -rf


all: $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	$(CC) -Iinclude $(CFLAGS) -o $@ $<
	

bonus: NEANT

clean:
	$(RMRF) $(OBJS)

fclean: clean
	$(RMRF) $(NAME)

re: fclean all

