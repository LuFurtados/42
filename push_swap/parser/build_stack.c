#include "push_swap.h"

int	build_stack(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	value;
	t_stack	*node;

	i = 1;
	while (i < argc)
	{
		if(!validate_number(argv[i]) || !check_overflow(argv[i]))
		{
			write(1, "Not a number / Overflow \n", 24);
			stack_clear(stack_a);
			return (0);
		}
		value = ft_atoi(argv[i]);
		if (check_duplicate(*stack_a, value))
		{
			write(1, "Duplicated\n", 11);
			stack_clear(stack_a);
			return (0);
		}
		node = stack_new(value);
		if (!node)
		{
			write(1, "Falhou stack_new\n", 17);
			stack_clear(stack_a);
			return (0);
		}
		stack_add_back(stack_a, node);
		i++;
	}
	return (1);
}
