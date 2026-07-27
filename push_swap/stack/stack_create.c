
#include "push_swap.h"

t_stack *stack_new(int value)
{
    t_stack *node;

    node = ft_calloc(1, sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = value;
    return (node);
}
