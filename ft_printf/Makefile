# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:42:04 by jehelee           #+#    #+#              #
#    Updated: 2023/01/05 16:24:15 by jehelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f
AR		= ar
ARFLAGS = crs

LIB_DIR = ./libft

SRCS	= ft_printf.c		\
		  ft_printf_utils_csp.c		\
		  ft_printf_utils_diu.c		\
		  ft_printf_utils_hex.c		\

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean : clean
	make -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/libft.a $@
	$(AR) $(ARFLAGS) $@ $^

 .PHONY : all clean fclean re