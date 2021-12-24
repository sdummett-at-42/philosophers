# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:05:51 by sdummett          #+#    #+#              #
#    Updated: 2021/12/24 18:41:19 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -c #-g#3 -fsanitize=address
NAME		= philo_bonus

INCLUDES	= $(wildcard include/*.h)

SRCS_DIR	= srcs/
OBJS_DIR	= objs/

SRCS_FILES	= main.c 

SRCS 		= $(addprefix ${SRCS_DIR}, ${SRC_FILES})

OBJS_FILES	= $(SRCS_FILES:.c=.o)
OBJS			= $(addprefix ${OBJS_DIR}, ${OBJS_FILES})

RMRF		= rm -rf

all: $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) -pthread $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	$(CC) -Iinclude $(CFLAGS) -o $@ $<

clean:
	$(RMRF) $(OBJS)

fclean: clean
	$(RMRF) $(NAME)

re: fclean all
