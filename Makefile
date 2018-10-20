# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbui <kbui@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 19:50:16 by kbui              #+#    #+#              #
#    Updated: 2018/10/19 20:06:45 by kbui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = b_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft.a

SRCS =	srcs/ls_docase.c \
		srcs/ls_filename_input.c \
		srcs/ls_filename.c \
		srcs/ls_print.c \
		srcs/ls_sorting.c \
		srcs/ls_dirname.c \
		srcs/main.c

INCS = incs/libft.h

RESET = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m

all: $(NAME)

$(NAME):
	@make -C libft/
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) libft/libft.a -I $(INCS) \
		-I srcs/libft/incs
	@printf "\n$(GREEN)[✓] $(RESET)\x1B[32m$(NAME) ready!\n\x1b[37m"

clean:
	@make -C libft/ clean
	
fclean:
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@printf "$(RED)[x] $(RESET)\x1B[31m$(NAME) deleted\n"

re: fclean all

.PHONY: all clean fclean re