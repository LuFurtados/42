
#include "push_swap.h"

int	find_max_position(t_stack *stack)
{
	int		max;
	int		position;
	t_stack	*current;

	max = stack->value;
	position = stack->position;
	current = stack;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			position = current->position;
		}
		current = current->next;
	}
	return (position);
}

void	rotate_to_top_b(t_stack **b, int pos)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(b);
			pos++;
		}
	}
}
