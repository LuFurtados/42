NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

ALGORITHM   = algorithm/cheapest.c \
              algorithm/cost.c \
              algorithm/metadata.c \
              algorithm/move.c \
              algorithm/final_rotate.c

OPERATIONS  = operations/push.c \
              operations/swap.c \
              operations/rotate.c \
              operations/reverse_rotate.c

PARSER      = parser/build_stack.c \
              parser/check_duplicate.c \
              parser/check_overflow.c \
              parser/validate_number.c

SORT        = sort/sort_five.c \
              sort/sort_stacks.c \
              sort/sort_tiny.c \
              sort/sort_turk.c

STACK       = stack/stack_add.c \
              stack/stack_clear.c \
              stack/stack_create.c \
              stack/stack_metadata.c \
              stack/stack_utils.c

UTILS       = utils/stack_print.c

SRC         = src/main.c \
              $(ALGORITHM) \
              $(OPERATIONS) \
              $(PARSER) \
              $(SORT) \
              $(STACK) \
              $(UTILS)

OBJS        = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re