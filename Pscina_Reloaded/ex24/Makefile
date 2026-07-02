NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
AR = ar rcs

INCDIR = includes

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c \
		srcs/ft_strcmp.c srcs/ft_strlen.c \
		srcs/ft_swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re