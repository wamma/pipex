# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:21:03 by hyungjup          #+#    #+#              #
#    Updated: 2023/01/16 14:51:58 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
LIB_DIR = ./libft
LIBFLAG = -lft -L$(LIB_DIR)

SRCS = pipex.c \
		error.c \
		find.c \
		free.c \

OBJS = $(SRCS:.c=.o)

HEADER = pipex.h

all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(LIBFLAG) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!"

%.o : %.c $(HEADER)
	@${CC} ${CFLAG} -c $< -o $@

clean :
	@$(RM) $(RMFLAG) $(OBJS)
	@make -C $(LIB_DIR) clean
	@rm -f make_mandatory
	@echo "$(YELLOW)object files deleted!"

fclean : clean
	@$(RM) $(NAME)
	@make -C $(LIB_DIR) fclean
	@echo "$(RED)all deleted"

re : fclean all

.PHONY : all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[0;33m