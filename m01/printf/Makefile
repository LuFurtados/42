NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	ft_printf.c ft_putchar_pf.c ft_puthex_pf.c ft_puthex_ptr_pf.c ft_putnbr_pf.c \
		ft_putnbr_unsint_pf.c ft_putptr_pf.c ft_putstr_pf.c ft_conversion_pf.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re