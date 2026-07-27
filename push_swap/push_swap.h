

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				cost_a;
	int				cost_b;
	int				target_position;
	struct s_stack	*next;
}	t_stack;

t_stack *stack_new(int value);
t_stack *stack_last(t_stack *node);
int	build_stack(int argc, char **argv, t_stack **stack_a);
int	validate_number(char *str);
int	check_overflow(char *str);
int	check_duplicate(t_stack *stack, int value);
int	stack_size(t_stack *stack);
int	stack_is_sorted(t_stack *stack);
int	stack_size(t_stack *stack);
int	stack_is_sorted(t_stack *stack);
void	stack_clear(t_stack **stack);
void 	stack_add_back(t_stack **stack, t_stack *new_node);
void	stack_print(t_stack *stack);
void	update_position(t_stack *stack);

#endif