NAME        = libftprintf.a
SRCS_DIR    = srcs/
INC_DIR     = include/

SRCS_FILES  = ft_printf.c \
              ft_handler.c \
              ft_handler_nbr.c

SRCS        = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS        = $(SRCS:.c=.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I $(INC_DIR)

AR          = ar rcs
RM          = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
