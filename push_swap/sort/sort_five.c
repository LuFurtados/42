
#include "push_swap.h"

static void push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
int min_pos;
int size;

update_position(*stack_a);
min_pos = find_min_position(*stack_a);
size = stack_size(*stack_a);
if (min_pos > size / 2)
{
while (min_pos < size)
{
rra(stack_a, 1);
min_pos++;
}
}
else
{
while (min_pos > 0)
{
ra(stack_a, 1);
min_pos--;
}
}
pb(stack_a, stack_b, 1);
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
int size;

size = stack_size(*stack_a);
while (size > 3)
{
push_smallest_to_b(stack_a, stack_b);
size--;
}
sort_three(stack_a);
while (*stack_b)
pa(stack_a, stack_b, 1);
}
