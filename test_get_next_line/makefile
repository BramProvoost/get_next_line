# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bprovoos <bprovoos@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/27 10:38:36 by bprovoos      #+#    #+#                  #
#    Updated: 2021/11/24 11:23:42 by bprovoos      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

m:
	@rm -rf write1.txt mandatory
	@touch write1.txt
	@gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 ../get_next_line.c ../get_next_line_utils.c main.c -o mandatory
	@./mandatory

b:
	@rm -rf write1.txt bonus
	@touch write1.txt
	@gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 ../get_next_line_bonus.c ../get_next_line_utils_bonus.c main.c -o bonus
	@./bonus

# @gcc -Wall -Wextra -Werror -g -fsanitize=address -D BUFFER_SIZE=5  ../get_next_line.c ../get_next_line_utils.c main.c