# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 14:50:14 by hyungjup          #+#    #+#              #
#    Updated: 2023/01/05 16:48:55 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f

SRCS = pipex.c \
		error.c \
		find.c \
		free.c \
		ft_split.c \
		utils.c 

OBJS = $(SRCS:.c=.o)

HEADER = pipex.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re