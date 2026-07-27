
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if(!build_stack(argc, argv, &stack_a))
	{
		stack_print(stack_a);
		return (1);
	}
	if (stack_is_sorted(stack_a))
	{
		write(1, "Sorted\n", 7);
		stack_clear(&stack_a);
		return (0);
	}
	else
	stack_print(stack_a);
	stack_clear(&stack_a);
	return (0);
}
