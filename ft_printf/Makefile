# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:42:04 by jehelee           #+#    #+#              #
#    Updated: 2023/01/03 17:44:19 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f
AR		= ar
ARFLAGS = crs

SRCS	= ft_printf.c		\
		  ft_printf_utils_csp.c		\
		  ft_printf_utils_diu.c		\
		  ft_printf_utils_hex.c		\

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

 .PHONY : all clean fclean re