# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprovoos <bprovoos@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/29 08:55:17 by bprovoos      #+#    #+#                  #
#    Updated: 2021/10/20 15:25:34 by bprovoos      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Change this data depends on your files you have

NAME		= get_next_line.a
HEADER		= src/get_next_line.h
SRCS		= src/get_next_line.o $\
			  src/get_next_line_utils.o

# The code below does not need to be changed

CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM 			= rm -rf
OBJ			= $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)


%.o: %.c $(HEADER)
	$(CC) -c $(FLAGS) -g -o $@ $<


clean:
	${RM} $(OBJ)


fclean: clean
	${RM} $(NAME)

re: fclean all


test:
	@#echo "\033c"
	@gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c test_get_next_line/main.c
	@./a.out

.PHONY: all clean fclean re test
