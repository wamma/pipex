# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 14:50:14 by hyungjup          #+#    #+#              #
#    Updated: 2022/12/28 14:50:16 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c \
		ft_print_hex.c \
		ft_print_ptr.c \
		ft_print_unsigned.c \
		ft_printf_utils.c \
		ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

 .PHONY : all clean fclean re