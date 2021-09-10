# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 18:00:45 by sdummett          #+#    #+#              #
#    Updated: 2021/09/10 21:11:13 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1		= create_thread.c
OBJ1		= $(SRC1:.c=.o)
TEST1		= create_thread

SRC2		= race_condition.c
OBJ2		= $(SRC2:.c=.o)
TEST2		= race_condition

SRC3		= mutex.c
OBJ3		= $(SRC3:.c=.o)
TEST3		= mutex

SRC4		= create_threads_in_loop.c
OBJ4		= $(SRC4:.c=.o)
TEST4		= create_thread_in_loop

SRC5		= thread_return_value.c
OBJ5		= $(SRC5:.c=.o)
TEST5		= thread_return_value

SRC6		= pass_args_to_threads.c
OBJ6		= $(SRC6:.c=.o)
TEST6		= pass_args_to_threads

SRC6		= sum_array_num.c
OBJ6		= $(SRC6:.c=.o)
TEST6		= sum_array_num

RM			= rm -f
CC			= clang
INC			= -Iinclude
CFLAGS		= -pthread -g3 -fsanitize=address
includes	= $(wildcard include/*.h)

%.o: %.c $(includes)
	$(CC) $(INC) -c $(CFLAGS) -o $@ $<

all: $(TEST1) $(TEST3) $(TEST5) $(TEST6) $(TEST7) # $(TEST2) $(TEST4)

$(TEST1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(TEST1)

$(TEST2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(TEST2)

$(TEST3): $(OBJ3)
	$(CC) $(CFLAGS) $(OBJ3) -o $(TEST3)

$(TEST4): $(OBJ4)
	$(CC) $(CFLAGS) $(OBJ4) -o $(TEST4)

$(TEST5): $(OBJ5)
	$(CC) $(CFLAGS) $(OBJ5) -o $(TEST5)

$(TEST6): $(OBJ6)
	$(CC) $(CFLAGS) $(OBJ6) -o $(TEST6)

$(TEST7): $(OBJ7)
	$(CC) $(CFLAGS) $(OBJ7) -o $(TEST7)

clean:
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)
	$(RM) $(OBJ4)
	$(RM) $(OBJ5)
	$(RM) $(OBJ6)
	$(RM) $(OBJ7)
	@printf "$(WHT)[$(YEL)$(TEST) OBJS REMOVED$(WHT)]\n"
	
fclean: clean
	$(RM) $(TEST1)
	$(RM) $(TEST2)
	$(RM) $(TEST3)
	$(RM) $(TEST4)
	$(RM) $(TEST5)
	$(RM) $(TEST6)
	$(RM) $(TEST7)
	@printf "$(WHT)[$(YEL)$(TEST) BINARIES REMOVED$(WHT)]\n"

re: fclean all	
