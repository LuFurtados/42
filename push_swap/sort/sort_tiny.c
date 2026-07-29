
#include "push_swap.h"

void sort_two(t_stack **stack_a)
{
if ((*stack_a)->value > (*stack_a)->next->value)
sa(stack_a, 1);
}

static t_stack *find_max(t_stack *stack)
{
t_stack *max_node;
int max_val;

max_node = stack;
max_val = stack->value;
while (stack)
{
if (stack->value > max_val)
{
max_val = stack->value;
max_node = stack;
}
stack = stack->next;
}
return (max_node);
}

void sort_three(t_stack **stack_a)
{
t_stack *max_node;

max_node = find_max(*stack_a);
if (*stack_a == max_node)
ra(stack_a, 1);
else if ((*stack_a)->next == max_node)
rra(stack_a, 1);
if ((*stack_a)->value > (*stack_a)->next->value)
sa(stack_a, 1);
}
