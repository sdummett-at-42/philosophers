# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 13:05:51 by sdummett          #+#    #+#              #
#    Updated: 2022/01/02 18:28:31 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -c #-g#3 -fsanitize=address
NAME		= philo_bonus

INCLUDES	= $(wildcard include/*.h)

SRCS_DIR	= srcs/
OBJS_DIR	= objs/

SRCS_FILES	=	main.c ft_atoi.c ft_strerror.c ft_strlen.c ft_msleep.c \
				gettime.c check_args.c is_number.c start_simulation.c \
				init_simulation.c launch_processes.c process_routine.c \
				wait_processes_end.c monitor_routine.c philosophers_actions.c \
				print_timestamp.c string_generator.c ft_calloc.c ft_rand.c \
				release_ressources.c solo_philosopher_routine.c

SRCS 		= $(addprefix ${SRCS_DIR}, ${SRC_FILES})

OBJS_FILES	= $(SRCS_FILES:.c=.o)
OBJS		= $(addprefix ${OBJS_DIR}, ${OBJS_FILES})

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

