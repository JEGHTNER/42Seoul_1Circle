CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c test.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = libft.h

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re