# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:05:51 by sdummett          #+#    #+#              #
#    Updated: 2022/01/02 18:07:52 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -c #-g#3 -fsanitize=address
NAME		= philo

INCLUDES	= $(wildcard include/*.h)

SRCS_DIR	= srcs/
OBJS_DIR	= objs/

SRCS_FILES	=	main.c ft_strlen.c ft_strerror.c is_number.c check_args.c ft_atoi.c \
				init_simulation.c start_simulation.c philosopher_routine.c \
				wait_threads_end.c \
				launch_threads.c release_ressources.c \
				gettime.c print_timestamp.c drop_forks.c monitor_routine.c \
				ft_msleep.c philosophers_actions.c philosophers_actions_on_forks.c \
				ft_calloc.c check_if_someone_died.c ft_msleep_wrapper.c \
				solo_philosopher_routine.c
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
	

bonus: NEANT

clean:
	$(RMRF) $(OBJS)

fclean: clean
	$(RMRF) $(NAME)

re: fclean all

