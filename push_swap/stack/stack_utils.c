
#include "push_swap.h"

t_stack *stack_last(t_stack *node)
{
    t_stack *current;

    if (!node)
        return (NULL);
    current = node;
    while (current->next)
        current = current->next;
    return (current);
}
int	stack_size(t_stack *stack)
{
    int i;

    if (!stack)
        return (0);
    i = 0;
    while (stack)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}
int	stack_is_sorted(t_stack *stack)
{
    t_stack *current;

    if (!stack)
        return (0);
    current = stack;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}
