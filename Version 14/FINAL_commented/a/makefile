# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:28:09 by uviana-a          #+#    #+#              #
#    Updated: 2023/09/29 18:28:11 by uviana-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

# Colors
RESET = \033[0m       # Text Reset
BLACK = \033[1;30m       # Black
RED = \033[1;31m         # Red
GREEN = \033[1;32m       # Green
YELLOW = \033[1;33m      # Yellow
BLUE = \033[1;34m       # Blue
PURPLE = \033[1;35m     # Purple
CYAN = \033[1;36m        # Cyan
WHITE = \033[1;37m       # White

NAME = push_swap

# Commands
CC	= cc
RM	= rm -rf

# Flags
CFLAGS = -Wall -Wextra -Werror -g -O0

# Files
SRC = 	main.c input_validation.c input_validation2.c sorting_algorithms.c initializing_stack.c\
		sorting_function.c setting_costs.c utils_functions.c \
		sort_over_five.c setting_index.c setting_pos_cost.c \
		setting_rotation_costs.c do_swap.c do_push.c \
		do_rotation.c do_rev_rotation.c print.c

OBJS = $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	printf "Compiling	$(GREEN)[OK]$(RESET)\n"

clean:
	$(RM) $(OBJS)
	printf "clean	       $(CYAN)[OK]$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "fclean	       $(CYAN)[OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re norm
